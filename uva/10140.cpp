#include <bits/stdc++.h>
using namespace std;
bool s[100000];
unsigned long long int p[100000];
unsigned long long int pr[1100000],prime[1100000];
void siv()
{
    for(int i=4; i<=47000; i+=2)
        s[i]=1;
    for(int i=3; i*i<=47000; i+=2)
    {
        if(s[i]==0)
        {
            for(int j=i*i; j<=47000; j+=i)
                s[j]=1;
        }
    }
    p[0]=2;
    for(int i=3,j=1; i<=47000; i+=2)
    {
        if(s[i]==0)
            p[j++]=i;
    }
}
void segmented_s(unsigned long long int m,unsigned long long int n)
{
    memset(pr,0,sizeof(pr));
    memset(pr,0,sizeof(pr));
    if(m==1)
        m++;
    for(int i=0; p[i]*p[i]<=n; i++)
    {
        int x=m/p[i];
        if(m%p[i]!=0)
            x++;
        for(int j=x*p[i]; j<=n; j+=p[i])
        {
            if(j!=p[i])
                pr[j-m]=1;
        }
    }
    int j=0;
    for(int i=0; i<=n-m; i++)
    {
        if(pr[i]==0)
            prime[j++]=i+m;
    }
    unsigned long long int mx=0,mi=9999999999,a=0,b=0,c=0,d=0;
    for(int i=1; i<j; i++)
    {
        if((prime[i]-prime[i-1])>mx)
        {
            mx=(prime[i]-prime[i-1]);
            c=prime[i-1];
            d=prime[i];
        }
        if((prime[i]-prime[i-1])<mi)
        {
            mi=(prime[i]-prime[i-1]);
            a=prime[i-1];
            b=prime[i];
        }
    }
    if(j<2)
        printf("There are no adjacent primes.\n");
    else
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n",a,b,c,d);
}
int main()
{
    siv();
    unsigned long long int m,n;
    while(scanf("%lld %lld",&m,&n)!=EOF)
        segmented_s(m,n);
}
