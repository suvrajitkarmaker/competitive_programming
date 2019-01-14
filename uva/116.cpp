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
#define valid(nx,ny,row,col)    nx>=0 && nx<row && ny>=0 && ny<col
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
#define eps 1e-8
ll a[15][110],n,m;
ll dp[15][110],path[15][110];
vector<int>v;
vector<pair<ll,ll> >vv;
ll call(int i,int j)
{


    if(j==m)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    ll p1,p2,p3,x1,x2,x3;
    p1=a[i][j]+call(i,j+1);
    x1=i;

    if(i==n-1)
    {
        p2=a[i][j]+call(0,j+1);
        x2=0;
    }
    else
    {
        p2=a[i][j]+call(i+1,j+1);
        x2=i+1;
    }


    if(i==0)
    {
        p3=a[i][j]+call(n-1,j+1);
        x3=n-1;
    }
    else
    {
        p3=a[i][j]+call(i-1,j+1);
        x3=i-1;
    }

    vv.clear();
    vv.push_back({p1,x1});
    vv.push_back({p2,x2});
    vv.push_back({p3,x3});
    sort(all(vv));

    path[i][j]=vv[0].second;
    dp[i][j]=vv[0].first;

    return dp[i][j];

}
int main()
{

 //READ("input.txt");
// WRITE("output.txt");
    while(scanf("%lld %lld",&n,&m)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                scanf("%lld",&a[i][j]);
        }
        CLR(dp,-1);
        CLR(path,-1);
        ll re=LONG_MAX,xx;
        int x=0;
        for(int i=0;i<n;i++)
        {
           xx=call(i,0);
           if(xx<re)
           {
               re=xx;
               x=i;
           }

        }



        v.clear();
        v.push_back(x+1);
        for(int i=0; i<m-1; i++)
        {
            x=path[x][i];
            v.push_back(x+1);
        }
        for(int i=0; i<v.size(); i++)
        {
            if(v.size()-1==i)
            {
                printf("%d\n",v[i]);
                continue;
            }
            printf("%d ",v[i]);
        }
        printf("%lld\n",re);
    }


}
