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
int ar[110],n,total,res;
int dp[110][20100];
int DP(int po,int vl)
{
    //cout<<total<<endl;
    if(vl>=total)
        return vl;
    if(po>=n)
        return INF;
    if(dp[po][vl]!=-1)
        return dp[po][vl];

    int p1=INF,p2=INF;
    p1=DP(po+1,vl);
    p2=DP(po+1,vl+ar[po]);
    dp[po][vl]=min(p1,p2);
    //cout<<dp[po][vl]<<endl;
    return dp[po][vl];

}
int ctDP(int po,int vl)
{
    if(vl==res)
        return 0;
    if(po>=n||vl>res)
    {
        return 200;
    }
    if(dp[po][vl]!=-1)
        return dp[po][vl];
    int p1=INF,p2=INF;
    p1=ctDP(po+1,vl);
    p2=1+ctDP(po+1,vl+ar[po]);
    return dp[po][vl]=min(p1,p2);
}
int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te;
    scanf("%d",&te);
    for(int i=0;i<te;i++)
    {
        scanf("%d %d",&total,&n);
        for(int j=0;j<n;j++)
            scanf("%d",&ar[j]);
        CLR(dp,-1);
        res=DP(0,0);
        CLR(dp,-1);
        int ct=ctDP(0,0);

        printf("%d %d\n",res,ct);
    }

}
