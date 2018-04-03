#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    long long int x=1;
    a[0]=1;
    for(long long int i=1; i<=10000; i++)
    {
        x*=i;
        if(x%10==0)
        {
            while(x%10==0)
                x/=10;
        }
        a[i]=x%10;
        x%=100000000000;
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%5d -> %d\n",n,a[n]);
    }
}
