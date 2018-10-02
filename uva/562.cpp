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
#define MAX 105
#define eps 1e-9
int cost[110],n,sum;
int dp[101][50005];
int DP(int po,int sm)
{

    if(po>=n)
    {
        int xx=sum-sm;
        return abs(sm-xx);
    }

    if(dp[po][sm]!=-1)
    return dp[po][sm];

    int p1=0,p2=0;
    p1=DP(po+1,sm);
    p2=DP(po+1,sm+cost[po]);

    dp[po][sm]=min(p1,p2);

    return dp[po][sm];

}

int main()
{

    int te;
    scanf("%d",&te);
    while(te--)
    {
        scanf("%d",&n);
        sum=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&cost[i]);
            sum+=cost[i];
        }

        CLR(dp,-1);

        int xx=DP(0,0);
        printf("%d\n",xx);
    }

}
