#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define gcd3(x,y,z)                __gcd(__gcd(x,y),z)
#define INF                     INT_MAX
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
int ar[25],dp[25],in[25],n;
int longest(int u)
{
    //cout<<"das"<<endl;
    if(dp[u]!=-1)
        return dp[u];
    int mx=0;
    for(int v=u+1; v<=n; v++)
    {
        if(ar[in[v]]>ar[in[u]])
        {
            if(longest(v)>mx)
            {
                mx=longest(v);
            }
        }
    }
    return dp[u]=1+mx;

}
int main()
{

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int x;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        ar[i+1]=x;
    }
//    CLR(dp,-1);
    while(scanf("%d",&x)!=EOF)
    {
        in[x]=1;
        for(int i=2; i<=n; i++)
        {
            scanf("%d",&x);
            in[x]=i;
        }
        int li=0;
        CLR(dp,-1);
        for(int i=1; i<=n; i++)
        {
            if(longest(i)>li)
            {
                li=longest(i);
            }
        }
        cout<<li<<endl;
    }
}
