#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,t,sum;
    while(cin>>n>>k)
    {
        sum=n;
        while((n/k)>=1)
        {
            t=n/k;
            sum+=t;
            n=t+(n%k);
        }
        cout<<sum<<endl;
    }
}
