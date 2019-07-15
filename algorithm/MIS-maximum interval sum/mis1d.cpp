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
            mx=max(sum[i+1],mx);
        }

    }
    return mx;
}

int main()
{

    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    cout<<mis(a,n);
}
