#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int dp[1005][105][105];
vector<int>a;
int hobe(int po,int ct,int sum)
{

    if(po>=n)
        return 0;
    if(ct>=k)
        return 0;
    int &ans=dp[po][ct][sum];
    if(ans!=-1)
        return ans;

    ans=hobe(po+1,ct,sum);
    if(a[po]+sum<=m)
        ans=max(ans,1+hobe(po+1,ct,sum+a[po]));
    else
        ans=max(ans,hobe(po,ct+1,0));
    return ans;


}
int main()
{
    char s[1000];
    int te;
    scanf("%d",&te);
    for(int ii=0; ii<te; ii++)
    {
        scanf("%d %d %d",&n,&m,&k);
        a.clear();
        for(int i=0; i<n; i++)
        {
            scanf("%s",s);
            int l=strlen(s);
            int x=0;
            if(s[l-1]==',')
                l--;
            for(int j=0; j<l; j++)
                x=(x*10)+s[j]-48;
            a.push_back(x);
        }
        memset(dp,-1,sizeof(dp));
        if(ii>0)
            printf("\n");
        printf("%d\n",hobe(0,0,0));
    }
}
