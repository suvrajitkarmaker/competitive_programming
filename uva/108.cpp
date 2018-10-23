#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[n][n],sum[n+1],mx=-99999999;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        }
        for(int i=0;i<n;i++)
        {
            memset(sum,0,sizeof(sum));
            for(int j=i;j<n;j++)
            {
                int s=0;
                for(int k=0;k<n;k++)
                {
                    sum[k]+=a[j][k];
                    s+=sum[k];
                    if(s<sum[k])
                        s=sum[k];
                    mx=max(s,mx);
                }
            }
        }
        printf("%d\n",mx);
    }
}
