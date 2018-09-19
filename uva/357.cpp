#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ar[]= {1,5,10,25,50};
ll dp[7][31000];
ll DP(ll po,ll sum)
{
    //cout<<dp[po][sum]<<endl;
    if(sum==0)
        return 1;
    if(po>=5||sum<0)
        return 0;

    if(dp[po][sum]!=-1)
        return dp[po][sum];
    ll p1=0,p2=0;
    p1=DP(po+1,sum);
    if(sum-ar[po]>=0)
        p2=DP(po,sum-ar[po]);

    dp[po][sum]=p1+p2;
    return dp[po][sum];
}
int main()
{
    ll te;
    memset(dp,-1,sizeof(dp));
    while(cin>>te)
    {
        ll res=DP(0,te);
        if(res==1)
            printf("There is only 1 way to produce %lld cents change.\n",te);
        else
            printf("There are %lld ways to produce %lld cents change.\n",res,te);

    }
}
