#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}

int main()
{
    int n,r;
    while(1)
    {
        scanf("%d %d",&n,&r);
        if(n==0 && r==0)
            break;
        int m=r,d=n-r,a[1000],b[1000];
        if(d>m)
        {
            m=d;
            d=r;
        }
        int l=0,k=0;
        for(int i=m+1; i<=n; i++)
            a[l++]=i;
        for(int i=2; i<=d; i++)
            b[k++]=i;
        for(int i=0; i<k; i++)
        {
            int j=0,x;
            while(j<l && b[i]!=1)
            {
                x=gcd(a[j],b[i]);
                a[j]/=x;
                b[i]/=x;
                j++;
            }

        }
        long long int mul=1;
        for(int i=0; i<l; i++)
            mul*=a[i];
        printf("%lld\n",mul);
    }
}
