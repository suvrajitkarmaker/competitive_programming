#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,m;
    scanf("%lld",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%lld %lld",&n,&m);
        if(m%n==0)
            printf("%lld %lld\n",n,m);
        else
            printf("-1\n");
    }
}
