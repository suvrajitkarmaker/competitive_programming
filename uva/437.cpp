#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
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
#define max3(x,y,z)             max(z,max(x,y));
#define min3(x,y,z)             min(z,min(x,y));
#define MP(x, y) make_pair(x, y)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define pii pair< int, int >
#define psi pair< string, int >
#define MAX 100100000
#define eps 1e-15
ll n,po,dp[200];
struct st
{
    ll x,y,z;
} ar[1000];

ll call(ll ps, ll xx,ll yy)
{

    if(ps==po)
        return 0;
    if(dp[ps]!=-1)
        return dp[ps];

    ll p1=0;

    for(int i=0; i<po; i++)
    {
        if(xx<ar[i].x && yy<ar[i].y)
            p1=max(p1,ar[i].z+call(i,ar[i].x,ar[i].y));
    }
    dp[ps]=p1;

    return dp[ps];
}


int main()
{

 //   READ("input.txt");
 //  WRITE("output.txt");
    ll ct=1;

    while(scanf("%lld",&n))
    {
        if(n==0)
            break;
        po=0;
        ll x,y,z;
        for(int i=0; i<n; i++)
        {
            scanf("%lld %lld %lld",&x,&y,&z);
            ar[po].x=x;
            ar[po].y=y;
            ar[po++].z=z;

            ar[po].x=x;
            ar[po].y=z;
            ar[po++].z=y;

            ar[po].x=y;
            ar[po].y=x;
            ar[po++].z=z;

            ar[po].x=y;
            ar[po].y=z;
            ar[po++].z=x;

            ar[po].x=z;
            ar[po].y=x;
            ar[po++].z=y;

            ar[po].x=z;
            ar[po].y=y;
            ar[po++].z=x;

        }

        CLR(dp,-1);
        printf("Case %lld: maximum height = %lld\n",ct++,call(0,0,0));
    }




}
