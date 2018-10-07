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
ll dp[52][52];
vector<ll>v;
ll DP(int l,int r)
{
    if(r<=l)
        return 0;
    if(r-l==1)
        return 0;

    if(dp[l][r]!=-1)
        return dp[l][r];
    ll re=v[r]-v[l],mi=LONG_MAX;


    for(int k=l+1; k<=r-1; k++)
    {
        mi=min(mi,re+DP(l,k)+DP(k,r));
    }
    dp[l][r]=mi;
    return dp[l][r];
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ll n,m,x;
    while(scanf("%lld",&n) && n)
    {
        scanf("%lld",&m);
        v.clear();
        v.push_back(0);
        for(int i=1; i<=m; i++)
        {
            scanf("%lld",&x);
            v.push_back(x);
        }
        v.push_back(n);
        //  cout<<v[m+1]<<endl;
        CLR(dp,-1);
        printf("The minimum cutting is %lld.\n",DP(0,v.size()-1));
    }
}
