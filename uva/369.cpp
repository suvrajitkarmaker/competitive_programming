#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF                     INT_MAX
#define inf                     LONG_MAX
#define PI                      (2.0*acos(0.0))
#define Log(b,x)                (log(x)/log(b))
#define all(x)                  (x).begin(), (x).end()
#define Unique(x)               sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x)          to_string(x)
#define stringtoint(x)          stoll(x)
#define valid(nx,ny,row,col)    nx>=0 && nx<row && ny>=0 && ny<col
#define CLR(x,y)                memset(x,y,sizeof(x));
#define MAX 100100
ll dp[105][105];
ll DP(ll n, ll r)
{
    if(n==r)
    return 1;
    if(r==1)
        return n;

    if(dp[n][r]!=-1)
        return dp[n][r];

    dp[n][r]=DP(n-1,r)+DP(n-1,r-1);
    return dp[n][r];
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,r;
    while(scanf("%lld %lld",&n,&r) && n && r)
    {
        CLR(dp,-1);
        printf("%lld things taken %lld at a time is %lld exactly.\n",n,r,DP(n,r));

    }

}
