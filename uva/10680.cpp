#include <bits/stdc++.h>
using namespace std;
bool s[1100000];
long long int a[1000000],l=1;
void siv()
{
    int n=1000000;
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
    a[0]=2;
    for(int i=3; i<=n; i+=2)
    {
        if(s[i]==0)
        {
            a[l++]=i;
        }
    }
}
int lcm(int n)
{
    long long int mul=1;
    for(int i=0; a[i]<=n && i<l; i++)
    {
        for(long long int j=a[i]; j<=n; j*=a[i])
        {
            mul*=a[i];
            while(mul%10==0)
                mul/=10;
            mul%=100000000;
        }
    }
    return mul%10;
}
int main()
{
    siv();
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        printf("%d\n",lcm(n));
    }
}
