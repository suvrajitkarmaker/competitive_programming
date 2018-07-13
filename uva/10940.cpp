#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF                     LLONG_MAX
#define inf                     LONG_MAX
#define PI                      (2.0*acos(0.0))
#define Log(b,x)                (log(x)/log(b))
#define all(x)                  (x).begin(), (x).end()
#define Unique(x)               sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x)          to_string(x)
#define stringtoint(x)          stoll(x)
#define valid(nx,ny,row,col)    nx>=0 && nx<row && ny>=0 && ny<col
#define CLR(x,y)                memset(x,y,sizeof(x));

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll a[500100];
    a[1]=1;
    a[2]=2;
    ll sum=2,tr=4;
    for(int i=3; i<=500000; i++)
    {
        if(tr==sum)
        {
            tr*=2;
            a[i]=sum;
            sum=2;
        }
        else
        {
            a[i]=sum;
            sum+=2;
        }


    }
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        printf("%lld\n",a[n]);
    }
}
