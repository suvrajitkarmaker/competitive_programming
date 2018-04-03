#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,t,i,j;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n>>m;
        int sum=0;
        for(j=n;j<=m;j++)
        {
            if(j%2!=0)
                sum=sum+j;
        }
        cout<<"Case "<<i<<": "<<sum<<endl;
    }
    return 0;
}
