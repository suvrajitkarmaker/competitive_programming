#include <bits/stdc++.h>
using namespace std;
int a[10000000],i;
int main()
{
    a[0]=1;
    a[1]=2;
    for(i=2;; i++)
    {
        a[i]=a[i-1]+a[i-2];
        if(a[i]>=100000000)
            break;
    }
    // sort(a,a+i,greater<int>());
    int t,n;
    scanf("%d",&t);
    for(int j=0; j<t; j++)
    {
        scanf("%d",&n);
        int up=upper_bound(a,a+i,n)-a;
        up--;
        printf("%d = ",n);
        for(int k=up; k>=0; k--)
        {
            if(a[k]<=n)
            {
                printf("1");
                n-=a[k];
            }
            else
                printf("0");

        }
        printf(" (fib)\n");
    }
}
