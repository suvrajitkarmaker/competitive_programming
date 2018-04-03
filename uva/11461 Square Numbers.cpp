#include <bits/stdc++.h>
#include <math.h>
using namespace std;
long long int f[5010];
long long int fib(int n)
{
    if(n<=1)
        return n;
    if(f[n]!=-1)
        return f[n];
    f[n]=fib(n-1)+fib(n-2);
    return f[n];
}
int main()
{
    long long int i,n;
    for(i=0; i<=5000; i++)
        f[i]=-1;
    fib(5000);
    while(scanf("%lld",&n)!=EOF)
        printf("The Fibonacci number for %lld is %lld\n",n,f[n]);
    return 0;
}
