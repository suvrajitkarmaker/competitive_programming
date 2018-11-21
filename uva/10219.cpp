#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
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
int main()
{
    ll n,k;
    long double sum=0;
    while(scanf("%llu %llu",&n,&k)!=EOF)
    {
        sum=0;
        for(ll i=n-k+1;i<=n;i++)
            sum+=log10(i);
        for(ll i=1;i<=k;i++)
            sum-=log10(i);
        printf("%d\n",(int)floor(sum)+1);
    }
}
