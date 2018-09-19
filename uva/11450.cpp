#include <bits/stdc++.h>
using namespace std;
vector<int>v[25];
int dp[25][250],m,n;
int DP(int po, int sum)
{
    // cout<<sum<<endl;
    if(po>=n)
        return sum;

    if(dp[po][sum]!=-1)
        return dp[po][sum];
    int p1=0,p2=0;
   // p1=max(p1,DP(po+1,sum));
    for(int i=0; i<v[po].size(); i++)
    {
        if(sum+v[po][i]<=m)
            p2=max(p2,DP(po+1,sum+v[po][i]));
    }
    dp[po][sum]=p2;
    return dp[po][sum];
}
int main()
{
    int k,x,te;
    cin>>te;
    for(int ii=0; ii<te; ii++)
    {
        scanf("%d %d",&m,&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&k);
            v[i].clear();
            for(int j=0; j<k; j++)
            {
                scanf("%d",&x);
                v[i].push_back(x);
            }
        }
        memset(dp,-1,sizeof(dp));
        int res=DP(0,0);
        if(res==0)
            printf("no solution\n");
        else
            printf("%d\n",res);
    }
}
