#include <bits/stdc++.h>
using namespace std;
int gcd(long long int a,long long int b)
{
    if(b==0)
        return a;
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}

int main()
{
    long long int c=0;
    for(int i=1;i<=1000;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(gcd(i,j)==1)
            c++;
        }
    }
    cout<<gcd(2147000000,1340599805)<<endl;
}
