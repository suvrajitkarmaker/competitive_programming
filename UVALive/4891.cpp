#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,m;
ll dp[55][55];
ll bt(int i,int j)
{
    //cout<<"dsa"<<endl;
    if(i==n && j==m)
        return 1;
    if(i>n||j>m)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    dp[i][j]=bt(i+1,j)+bt(i,j+1);
    return dp[i][j];
}
int main()
{
    int ct=1;
    while(scanf("%d %d",&m,&n))
    {
        if(n==0 && m==0)
            break;
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %lld\n",ct++,bt(1,1));
    }
}
