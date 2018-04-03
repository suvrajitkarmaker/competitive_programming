#include <bits/stdc++.h>
using namespace std;
bool s[1000000];
long long int a[1000000],l=1;
void siv()
{
    int n=47000;
    for(int i=4; i<=n; i+=2)
    {
        s[i]=1;
    }
    for(int i=3; i*i<=n; i+=2)
    {
        if(s[i]==0)
        {
            for(int j=i*i; j<=n; j+=i)
                s[j]=1;
        }
    }
    s[1]=1;
    a[0]=2;
    for(int i=3; i<=n; i+=2)
    {
        if(s[i]==0)
        {
            a[l++]=i;
        }
    }
}
long long int pf(long long int n)
{
    if(n==1)
        return 2;
    long long int x=n,sum=0,mu;
    for(int i=0;i<l && a[i]*a[i]<=n;i++)
    {
        if(n%a[i]==0)
        {
            mu=1;
            while(n%a[i]==0)
            {
                mu*=a[i];
                n/=a[i];
            }
            sum+=mu;
        }
    }
    if(n>1)
        sum+=n;
    if(sum==x)
        sum++;
    return sum;
}
int main()
{
    siv();
    long long int n;
    int i=1;
    while(scanf("%lld",&n)&& n)
        printf("Case %d: %lld\n",i++,pf(n));
}
