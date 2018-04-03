#include <bits/stdc++.h>
#define M 31623
#define lli long long int
using namespace std;
bool s[M+10];
vector<int>p;
void siv()
{
    int n=M;
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
    p.push_back(2);
    for(int j=3;j<=M;j+=2)
    {
        if(s[j]==0)
            p.push_back(j);
    }
}
int prime(lli n)
{
    if(n<=M)
        return s[n];
    int t=p.size();
    for(int i=0;p[i]*p[i]<=n&&i<=t;i++)
    {
        if(n%p[i]==0)
        {
            return 1;
            break;
        }
    }
    return 0;
}
lli bigmod(lli b, lli p, lli m)
{
    if(p==0)
        return 1 % m;
    lli x=(bigmod(b,p/2,m));
    x=(x*x)%m;
    if(p%2==1)
        x=(b*x)%m;
    return x;
}
int main()
{
    siv();
    lli p,a;
    while(scanf("%lld %lld",&p,&a))
    {
        if(p==0 && a==0)
            break;
        if(prime(p)==1)
        {
            if(bigmod(a,p,p)==a)
                printf("yes\n");
            else
                printf("no\n");
        }
        else
            printf("no\n");
    }
}
