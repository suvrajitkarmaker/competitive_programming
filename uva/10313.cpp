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
ll lo,hi,mk;
ll dp[310][310];
ll DP(ll po,ll sum)
{
    if(sum==0)
        return 1;
    if(po==0||sum<0)
        return 0;
    if(dp[po][sum]!=-1)
        return dp[po][sum];
    ll p1=0,p2=0;

    if(sum-po>=0)
        p2=DP(po,sum-po);
p1=DP(po-1,sum);
    return dp[po][sum]=p1+p2;

}
int main()
{

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    CLR(dp,-1);
    int f1,n;
    char str[20];
    while(gets(str))
    {
        lo=-1;
        hi=-1;
        sscanf(str,"%lld%lld%lld",&mk,&lo,&hi);
        lo=min(lo,300ll);
        hi=min(hi,300ll);
        if(lo==-1)
            printf("%lld\n",DP(mk,mk));
        else if(hi==-1)
            printf("%lld\n",DP(lo,mk));
        else
        {
            if(lo==0)
                printf("%lld\n",DP(hi,mk));
            else
            {
                printf("%lld\n",DP(hi,mk)-DP(lo-1,mk));
            }
        }
    }

}
