#include <bits/stdc++.h>
using namespace std;
bool s[70000];
long long int a[70000];
void siv()
{
    int n=65000;
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
}
long long int bigmod(long long int b, long long int p, long long int m)
{
    if(p==0)
        return 1 % m;
    long long int x=(bigmod(b,p/2,m));
    x=(x*x)%m;
    if(p%2==1)
        x=(b*x)%m;
    return x;
}
int main()
{
    siv();
    long long int n,i;
    while(scanf("%lld",&n))
    {
        if(n==0)
            break;
        if(s[n]==1)
        {
            for(i=2; i<=n-1; i++)
            {
                if(bigmod(i,n,n)!=i)
                    break;
            }
            if(i==n)
                printf("The number %d is a Carmichael number.\n",n);
            else
                printf("%d is normal.\n",n);

        }
        else
            printf("%d is normal.\n",n);
    }
}
