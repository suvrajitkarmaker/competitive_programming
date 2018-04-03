#include <bits/stdc++.h>
using namespace std;
bool s[1100000];
long long int a[1000000];
void siv()
{
    int n=1000000;
    for(int i=4;i<=n;i+=2)
        s[i]=true;
    for(int i=3;i*i<=n;i+=2)
    {
        if(s[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)
                s[j]=true;
        }
    }
    for(int i=2,j=0;i<=n;i++)
    {
        if(s[i]==0)
            a[j++]=i;
    }
}
void sum(int n)
{
    int t=0,i;
    for(i=0;a[i]*a[i]<=n;i++)
    {
        if(s[n-a[i]]==0)
        {
            t=1;
            break;
        }
    }
    if(t==0)
        printf("%d:\nNO WAY!\n",n);
    else
    {
        printf("%d:\n%lld+%lld\n",n,a[i],n-a[i]);
    }
}
int main()
{
    siv();
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        sum(n);
    }
}
