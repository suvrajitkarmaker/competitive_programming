#include<bits/stdc++.h>
using namespace std;
int mis(int a[],int n)
{
    int sum[n+10],mx=INT_MIN;
    sum[0]=0;
    for(int i=0;i<n;i++)
    {
        if(sum[i]+a[i]<=a[i])
        {
            sum[i+1]=a[i];
        }
        else
        {
            sum[i+1]=sum[i]+a[i];
        }
          mx=max(sum[i+1],mx);

    }
    return mx;
}

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
                    if(s>=0)
                        s+=sum[k];
                    else
                        s=sum[k];
                    mx=max(s,mx);
                }
            }
        }
        printf("%d\n",mx);
    }
}
