#include <bits/stdc++.h>
using namespace std;
bool s[51000];
long long int a[51000];
long long int m;
void siv()
{
    int sq=sqrt(50000),n=50000,i,j;
    for(i=4; i<=n; i+=2)
        s[i]=1;
    for(i=3; i<=sq; i+=2)
    {
        if(s[i]==0)
        {
            for(j=i*i; j<=n; j+=i)
                s[j]=1;
        }
    }
    s[1]=1;
    a[0]=2;
    for(i=3,j=1; i<=n; i+=2)
    {
        if(s[i]==0)
            a[j++]=i;
    }
}
long long int factor(long long int n,long long int j)
{
    long long int co=0;
    while(n%j==0)
    {
        if(m%j==0)
            m/=j;
        n/=j;
    }
    return co;
}
long long int re(long long int n)
{
    long long int s,x=sqrt(n)+1;
    for(int i=0; a[i]<=x; i++)
    {
        if(m%a[i]==0)
        {
            for(int j=a[i]; j<=n; j+=a[i])
            {
                factor(j,a[i]);
                if(m==1)
                    break;
            }
        }
        if(m==1)
            break;
    }
    //cout<<m<<endl;
    if(m==1)
        return 0;
    else
        return 1;
}
int main()
{
    siv();
    long long int n,x;
    while(scanf("%lld %lld",&n,&m)!=EOF)
    {
        int t;
        x=m;
        t=re(n);
        if(t==1)
            printf("%lld does not divide %lld!\n",x,n);
        else
            printf("%lld divides %lld!\n",x,n);
    }
}
