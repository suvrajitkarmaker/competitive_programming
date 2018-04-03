#include <bits/stdc++.h>
using namespace std;
int g(int po,long long int n)
{
    long long int m,l,c=0,x=0;
    m=n;
    while(m>9)
    {
        x=(x*10)+(m%10);
        m/=10;
    }
    x=(x*10)+m;
    if(x==n)
    {
        cout<<po<<" "<<x<<endl;
        return 0;
    }
    else
        g(po+1,x+n);
}
int main()
{
    long long int n,te;
    cin>>te;
    for(int i=0; i<te; i++)
    {
        cin>>n;
        g(0,n);
    }
}
