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
int a[10005],b[10005],n;
int dp[10005];
int lis(int u)
{

    if(dp[u]!=-1)
        return dp[u];

    int mx=0;

    for(int v=u+1;v<n;v++)
    {
        if(a[v]>a[u])
        {
            int dd=lis(v);
            if(dd>mx)
            mx=dd;
        }
    }

    dp[u]=b[u]+mx;

    return dp[u];


}
int lds(int u)
{

    if(dp[u]!=-1)
        return dp[u];

    int mx=0;

    for(int v=u+1;v<n;v++)
    {
        if(a[v]<a[u])
        {
            int dd=lds(v);
            if(dd>mx)
            mx=dd;
        }
    }

    dp[u]=b[u]+mx;

    return dp[u];


}
int main()
{
    int ct=1,te;
    cin>>te;
    while(te--)
    {

        scanf("%d",&n);

        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(int i=0; i<n; i++)
            scanf("%d",&b[i]);

        int ls=0;
        CLR(dp,-1);
        for(int i=0;i<n;i++)
        {
            ls=max(ls,lis(i));
        }
        int ld=0;
        CLR(dp,-1);
        for(int i=0;i<n;i++)
        {
            ld=max(ld,lds(i));
        }
       // cout<<ls<<endl;


        if(ls>=ld)
            printf("Case %d. Increasing (%d). Decreasing (%d).\n",ct++,ls,ld);
        else
           printf("Case %d. Decreasing (%d). Increasing (%d).\n",ct++,ld,ls);
    }


}
