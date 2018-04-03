#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m;
    while(scanf("%lld %lld",&n,&m)!=EOF)
    {
        long long int x=1,d;
        for(long long int i=n-m+1; i<=n; i++)
        {
            x*=i;
            if(x%10==0)
            {
                while(x%10==0)
                    x/=10;
            }
            x%=100000000000;
        }
        x%=10;
        printf("%lld\n",x);
    }

}
