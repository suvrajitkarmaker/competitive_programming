#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define gcd3(x,y,z)                __gcd(__gcd(x,y),z)
#define INF                     LLONG_MAX
#define inf                     LONG_MAX
#define PI                      (2.0*acos(0.0))
#define Log(b,x)                (log(x)/log(b))
#define all(x)                  (x).begin(), (x).end()
#define Unique(x)               sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x)          to_string(x)
#define stringtoint(x)          stoll(x)
#define valid(nx,ny,row,col)    nx>0 && nx<=row && ny>0 && ny<=col
#define CLR(x,y)                memset(x,y,sizeof(x));
#define MAX 105
#define eps 1e-9
string s;
int le,num,mark[150],str[150],f=0;
void BT(int po,int ct)
{
    if(f==1)
        return;
    if(po>=num)
    {
        f=1;
        return;
    }

    int tmp=s[ct]-48;
    if(mark[tmp]==0 && tmp>=1 && tmp<=num)
    {
        mark[tmp]=1;
        str[po]=tmp;
        BT(po+1,ct+1);
        mark[tmp]=0;

    }
    if(f==1)
        return;
    if(ct+1<le)
    {
        tmp*=10;
        tmp+=s[ct+1]-48;
        if(mark[tmp]==0 && tmp>=1 && tmp<=num)
        {
            mark[tmp]=1;
            str[po]=tmp;
            BT(po+1,ct+2);
            mark[tmp]=0;
        }
    }
}
int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(cin>>s)
    {
        CLR(str,0);
        CLR(mark,0);
        f=0;
        le=s.size();
        if(le<=9)
            num=le;
        else
        {
            num=le-9;
            num/=2;
            num+=9;
        }
        BT(0,0);
        for(int i=0; i<num-1; i++)
        {
            printf("%d ",str[i]);
        }
        printf("%d\n",str[num-1]);
    }

}
