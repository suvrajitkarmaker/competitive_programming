#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,t,sum;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>n;
        int a[n],median,sum=0;
        for(int j=0; j<n; j++)
            cin>>a[j];
        sort(a,a+n);
        median=n/2;
        for(int j=0;j<n;j++)
            sum+=abs(a[j]-a[median]);
        cout<<sum<<endl;
    }
}
