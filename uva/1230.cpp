#include <bits/stdc++.h>
using namespace std;
long long int bigmod(long long int a,long long int b, long long int m)
{
    if(b==0)
        return 1%m;
    int x=bigmod(a,b/2,m);
    x=(x*x)%m;
    if(b%2==1)
        x=(x*a)%m;
    return x;
}
int main()
{
    long long int n,x,y,z;
    while(cin>>n)
    {
        if(n==0)
            break;
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y>>z;
            cout<<bigmod(x,y,z)<<endl;
        }
    }
}
