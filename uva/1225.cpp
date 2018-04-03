#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,t;
    int a[15];
    cin>>t;
    for(int k=0; k<t; k++)
    {
        for(int j=0; j<=9; j++)
            a[j]=0;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            m=i;
            while(m>9)
            {
                a[m%10]++;
                m=m/10;
            }
            a[m]++;
        }
        for(int i=0; i<=8; i++)
            cout<<a[i]<<" ";
        cout<<a[9]<<endl;
    }
}
