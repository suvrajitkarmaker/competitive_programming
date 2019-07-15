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
int cost[2010],wigt[2010],n,we;
int dp[2010][2010];
int fn(int i,int w)
{

    if(i==n)
    return 0;

    if(dp[i][w]!=-1)
    return dp[i][w];

    int p1=0,p2=0;

    p1=fn(i+1,w);
    if(wigt[i]+w<=we)
    {
        p2=cost[i]+fn(i+1,wigt[i]+w);
    }

    dp[i][w]=max(p1,p2);

    return dp[i][w];

}

int main()
{
    CLR(dp,-1);

    cin>>we>>n;
    for(int i=0;i<n;i++)
    scanf("%d %d",&wigt[i],&cost[i]);

    printf("%d\n",fn(0,0));

}
