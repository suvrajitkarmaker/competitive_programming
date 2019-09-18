#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

typedef long double ld;
typedef long long ll;

typedef pair<ll,ll> pii;

const int INF = int(1e9);
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define gcd3(x,y,z)                __gcd(__gcd(x,y),z)
#define inf                     LONG_MAX
#define PI                      (2.0*acos(0.0))
#define Log(b,x)                (log(x)/log(b))
#define Unique(x)               sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x)          to_string(x)
#define stringtoint(x)          stoll(x)
#define valid(nx,ny,row,col)    nx>=0 && nx<row && ny>=0 && ny<col
#define CLR(x,y)                memset(x,y,sizeof(x));
#define max3(x,y,z)             max(z,max(x,y));
#define min3(x,y,z)             min(z,min(x,y));
#define lccm(x,y)                (x*y)/__gcd(x,y);
#define MP(x, y) make_pair(x, y)
#define SZ(c) (int)c.size()
#define pb(x) push_back(x)
#define all(x)                  (x).begin(), (x).end()
#define sz(c)               int(c.size())
#define clr(x, y)           memset(x, y, sizeof(x))
#define ff first
#define ss                  second
#define sf                  scanf
#define si(x)               scanf("%d", &x)
#define sii(x, y)           scanf("%d %d", &x, &y)
#define siii(x, y, z)       scanf("%d %d %d", &x, &y, &z)
#define sl(x)               scanf("%lld", &x)
#define sll(x, y)           scanf("%lld %lld", &x, &y)
#define slll(x, y, z)       scanf("%lld %lld %lld", &x, &y, &z)
#define pf                  printf
#define pi(x)               printf("%d\n", x)
#define pii(x, y)           printf("%d %d\n", x, y)
#define piii(x, y, z)       printf("%d %d %d\n", x, y, z)
#define pl(x)               printf("%lld\n", x)
#define pll(x, y)           printf("%lld %lld\n", x, y)
#define plll(x, y, z)       printf("%lld %lld %lld\n", x, y, z)
#define loop(i, y)          for(int i=0; i<int(y); i++)
#define forn(i, x, y)       for(int i=int(x); i<=int(y); i++)
#define rofn(i, x, y)       for(int i=int(x); i>=int(y); i--)
#define bitCheck(N,in)      ((bool)(N&(1LL<<(in))))
#define bitOff(N,in)        (N&(~(1LL<<(in))))
#define bitOn(N,in)         (N|(1LL<<(in)))
#define bitFlip(a,k)        (a^(1LL<<(k)))
#define bitCount(a)         __builtin_popcount(a)
#define bitCountLL(a)       __builtin_popcountll(a)
#define bitRightMost(a)     __builtin_ctzll(a)
#define bitLeftMost(a)      (63-__builtin_clzll(a))

#define case(n) printf("Case %d: ",n);
#define eps 1e-15
#define mod 1000003
#define MAX 1000003
//priority_queue <ll, vector<ll>, greater<ll> > pq;
#define pointin(p)        scanf("%lf %lf", &p.x, &p.y)
vector<int>gp[50010];
int sum[50010],vis[50010];
int dfs(int u)
{
    vis[u]=1;
    int sm=0;
    for(int j=0;j<gp[u].size();j++)
    {
        if(vis[gp[u][j]]==0)
        {
            sm+=1+dfs(gp[u][j]);
        }
    }
    vis[u]=0;
    sum[u]=sm;
    return sm;
}
int main()
{
    int te,n,x,y;
    scanf("%d",&te);
    for(int i=1; i<=te; i++)
    {
        scanf("%d",&n);
        for(int j=0; j<=n; j++)
            gp[j].clear();
        clr(vis,0);
        clr(sum,-1);

        for(int j=0; j<n; j++)
        {
            scanf("%d %d",&x,&y);
            gp[x].push_back(y);
        }
        int mx=0,ans=0;
        for(int j=1;j<=n;j++)
        {
            if(sum[j]==-1)
                dfs(j);
            if(sum[j]>mx)
            {
                mx=sum[j];
                ans=j;
            }
        }
        printf("Case %d: %d\n",i,ans);
    }
}
