#include <bits/stdc++.h>
using namespace std;
int dev(long long int n)
{
    if(n==1)
        return 1;
    long long int x[100000],j=2;
    x[0]=1;
    x[1]=n;
    int sq=sqrt(n);

    for(int i=2; i<=sq; i++)
    {
        if(n%i==0)
        {
            x[j++]=i;
            if(i!=n/i)
                x[j++]=n/i;
        }
    }
    int sum=j,tm;
    sort(x,x+j);
    for(int i=1; i<j-1; i++)
    {
        for(int k=i+1; k<j-1; k++)
        {
            tm=__gcd(x[i],x[k]);
            if((x[i]*x[k])%tm==0 && (x[i]*x[k])/tm==n)
            {
                //cout<<x[i]<<" "<<x[k]<<endl;
                sum++;
            }
        }
    }
    return sum;
}
int main()
{
    long long int n;
    while(scanf("%lld",&n) && n)
    {
        printf("%lld %d\n",n,dev(n));
    }

}
