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
int ar[]={50,25,10,5,1};
int dp[7][8000],value;
int DP(int po,int vl)
{
    if(po>=5)
    {
        if(vl==0)
            return 1;
        return 0;
    }
    if(dp[po][vl]!=-1)
        return dp[po][vl];
    int p1=0,p2=0;
    p1=DP(po+1,vl);
    if(vl-ar[po]>=0)
    p2=DP(po,vl-ar[po]);

    dp[po][vl]=p1+p2;
    return dp[po][vl];
}
int main()
{

    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    CLR(dp,-1);
    while(scanf("%d",&value)!=EOF)
    {
        printf("%d\n",DP(0,value));
    }


}
