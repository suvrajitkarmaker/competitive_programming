#include<bits/stdc++.h>
using namespace std;
void d(long long int n)
{
    if(n>=10000000)
    {
        d(n/10000000);
        printf(" kuti");
        n%=10000000;
    }
    if(n>=100000)
    {
        d(n/100000);
       printf(" lakh");
        n%=100000;
    }
    if(n>=1000)
    {
        d(n/1000);
        printf(" hajar");
        n%=1000;
    }
    if(n>=100)
    {
        d(n/100);
        printf(" shata");
        n%=100;
    }
    if(n)
        printf (" %d",n);
}
int main()
{
    long long int n;
    int i=1;
    while(scanf("%lld",&n)!=EOF)
    {
        printf("%4d.",i++);
        if(n==0)
            printf(" 0");
        d(n);
        printf("\n");
    }
}
