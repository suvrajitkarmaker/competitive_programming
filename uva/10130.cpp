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
int cost[1010],weight[1010],n,sum;
int dp[1010][35];
int DP(int po,int sm)
{

    if(po>=n)
        return 0;
    if(dp[po][sm]!=-1)
        return dp[po][sm];

    int p1=0,p2=0;
    p1=DP(po+1,sm);

    if(sm>=weight[po])
        p2=cost[po]+DP(po+1,sm-weight[po]);

    dp[po][sm]=max(p1,p2);

    return dp[po][sm];

}

int main()
{

    int te,q;
    scanf("%d",&te);
    while(te--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d %d",&cost[i],&weight[i]);
        scanf("%d",&q);
        sum=-1;
        int qr[q];
        for(int i=0; i<q; i++)
        {
            scanf("%d",&qr[i]);
            //sum=max(sum,qr[i]);
        }
        CLR(dp,-1);
       // DP(0,0);
        int res=0;
        for(int i=0; i<q; i++)
        {
            res+=DP(0,qr[i]);
        }
        printf("%d\n",res);
    }

}
