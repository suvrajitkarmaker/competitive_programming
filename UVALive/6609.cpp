#include<bits/stdc++.h>
using namespace std;
int mis(int a[],int n,int p)
{
    int sum[n+10],ans=INT_MAX;
    sum[0]=0;
    for(int i=0; i<n; i++)
    {
        if(sum[i]+a[i]<=a[i])
        {
            sum[i+1]=a[i];
        }
        else
        {
            sum[i+1]=sum[i]+a[i];
            if(sum[i+1]>=p)
            {
                int ct=0,sm=0;
                for(int j=i; j>=0 &&  sm<p && ct<ans; j--)
                {
                    sm+=a[j];
                    ct++;
                }
                ans=min(ans,ct);
            }
        }

    }
    return ans;
}

int main()
{

    int n,p,te;
    scanf("%d",&te);
    while(te--)
    {
        scanf("%d %d",&n,&p);
        int a[n];
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        int xx=mis(a,n,p);
        if(xx==INT_MAX)
            printf("-1\n");
        else
            printf("%d\n",xx);
    }
}
