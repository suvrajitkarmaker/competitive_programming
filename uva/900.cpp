#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[100];
    a[0]=0;
    a[1]=1;
    a[2]=2;
    for(int i=3;i<=50;i++)
        a[i]=a[i-1]+a[i-2];
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        printf("%d\n",a[n]);
    }
}
