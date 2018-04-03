#include <bits/stdc++.h>
using namespace std;
#define maxN 100000001
bool s[maxN];
long long int a[100000000];
void siv()
{
    int n=100000000,sq;
    sq=sqrt(n);
    for(int i=4; i<=n; i+=2)
        s[i]=1;
    for(int i=3; i<=sq; i+=2)
    {
        if(s[i]==0)
        {
            for(int j=i*i; j<=n; j+=i)
                s[j]=1;
        }
    }
    a[0]=2;
    for(int i=3,j=1; i<=n; i+=2)
    {
        if(s[i]==0)
            a[j++]=i;
    }
}
void tp(int n)
{
    if(n<4)
    {
        printf("%d is not the sum of two primes!\n",n);
        return;
    }
    if(n%2==1)
    {
        if(s[n-2]==0)
             printf("%d is the sum of %d and %d.\n",n,2,n-2);
        else
             printf("%d is not the sum of two primes!\n",n);
        return;
    }
    int t=0,x=n/2;
    if(n%2==0)
        x--;
    if(x%2==0 && x!=2)
        x--;
    while(x>1)
    {
        if((n-x)%2==0);
        else if(s[x]==0 && s[n-x]==0)
        {
            t=1;
            break;
        }
        if(x-1==2)
            x--;
        else
        x-=2;
    }
    if(t==0)
        printf("%d is not the sum of two primes!\n",n);
    else
        printf("%d is the sum of %d and %d.\n",n,x,n-x);
}
int main()
{
    siv();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        tp(n);
    }
}
