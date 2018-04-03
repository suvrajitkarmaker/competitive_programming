#include <bits/stdc++.h>
using namespace std;
long long int x,m,i=1;
int f(long long int t,long long int n)
{
    if(n==1)
    {
        printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",i++,m,x,t+1);
        return 0;
    }
    if(n>x)
    {
        printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",i++,m,x,t);
        return 0;
    }
    if(n%2==0)
        f(t+1,(n/2));
    else
        f(t+1,((3*n)+1));
}
int main()
{
    while(1)
    {
        cin>>m>>x;
        if(m<0&&x<0)
            break;
        f(0,m);
    }
}
