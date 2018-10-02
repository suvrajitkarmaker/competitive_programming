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
int total,weight[40],cost[40],te;
int dp[40][1010],trk[40][1010];
int DP(int i,int w)
{

    if(i==te)
        return 0;

    if(dp[i][w]!=-1)
        return dp[i][w];
    int p1=0,p2=0;
    p1=DP(i+1,w);
    if(weight[i]+w<=total)
    {
        p2=cost[i]+DP(i+1,weight[i]+w);
    }

    if(p1>=p2)
        trk[i][w]=0;
    else
        trk[i][w]=1;
    dp[i][w]=max(p1,p2);
    return dp[i][w];
}
int main()
{

    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int cs,x,ttt=0;
    while(scanf("%d %d",&total,&cs)!=EOF)
    {
        scanf("%d",&te);
        CLR(dp,-1);
        CLR(trk,0);
        for(int i=0; i<te; i++)
        {
            scanf("%d %d",&x,&cost[i]);
            weight[i]=cs*x;
            weight[i]+=2*weight[i];
        }
        if(ttt>0)
            printf("\n");
        ttt++;
        printf("%d\n",DP(0,0));
        int sum=0,cnt=0;
        for(int i=0; i<te; i++)
        {
            if(trk[i][sum])
            {
                cnt++;
                sum+=weight[i];
            }
        }
        printf("%d\n",cnt);
        sum=0;
        for(int i=0; i<te; i++)
        {
            if(trk[i][sum])
            {
                printf("%d %d\n",weight[i]/(3*cs),cost[i]);
                sum+=weight[i];
            }
        }

    }


}
