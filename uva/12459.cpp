#include <bits/stdc++.h>
using namespace std;
int main()
{
   long long  int a[100];
    a[1]=1;
    a[2]=2;
    for(int i=3;i<=81;i++)
        a[i]=a[i-1]+a[i-2];
    int n;
    while(scanf("%d",&n)&& n!=0)
    {
        printf("%lld\n",a[n]);
    }
}
