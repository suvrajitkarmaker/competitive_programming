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
#define MAX 100100000
#define eps 1e-15
vector<int>v;
int res[1000010],tmp[1000010],p[1000100];
void print(int po)
{
    if(po<0)
        return;
    print(res[po]);
    printf("%d\n",v[po]);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,endd=0,l=0;
    while(scanf("%d",&n)!=EOF)
    {
        v.push_back(n);
    }
    for(int i=0; i<v.size(); i++)
    {
        int po=lower_bound(p,p+l,v[i])-p;
        p[po]=v[i];
        tmp[po]=i;
        res[i]= po>0 ? tmp[po-1] : -1;
        if(po==l)
        {
            l++;
            endd=i;
        }
        if(po+1==l)
            endd=i;

    }
    //sort(all(p));
    cout<<l<<endl;
    printf("-\n");
   print(endd);

}
