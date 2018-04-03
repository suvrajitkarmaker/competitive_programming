#include <bits/stdc++.h>
using namespace std;
long long int a[10000000],b[10000000];
void fib()
{
    a[0]=1;
    a[1]=1;
    b[0]=1;
    b[1]=2;
    for(int i=2; ; i++)
    {
        a[i]=a[i-1]+a[i-2];
        b[i]=b[i-1]+a[i];
        if(b[i]>4294967296)
            break;
    }
}
int main()
{
    fib();
    int n;
    while(scanf("%d",&n))
    {
        if(n==-1)
            break;
        printf("%lld %lld\n",b[n]-a[n],b[n]);

    }

}
