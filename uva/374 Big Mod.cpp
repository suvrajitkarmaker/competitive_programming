#include <bits/stdc++.h>
using namespace std;
long long int bigmod(int b, int p, int m)
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
    long long int x,y,z,i,t;

    while(scanf("%lld %lld %lld",&x,&y,&z)!=EOF)
    {
        long long int m=bigmod(x,y,z);
        printf("%lld\n",m);
    }
    return 0;
}
