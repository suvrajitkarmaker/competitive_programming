#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    long long int n,d;
    while(scanf("%lld",&n)!=EOF)
    {
        d=n/2;
        d++;
        d*=d;
        d=(d*2)-1;
        printf("%lld\n",d-4+d-2+d);
    }
}
