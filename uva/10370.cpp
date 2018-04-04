#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>m;
        int a[m],sum=0,c=0,s=0,x;
        double t;
        for(j=0; j<m; j++)
        {
            cin>>a[j];
            sum=sum+a[j];
        }
        x=sum/m;
        for(j=0; j<m; j++)
        {
            if(a[j]>x)
            {
                c++;
            }
        }
        t=(c*100.0)/m;
        printf("%0.3lf",t);
        cout<<"%"<<endl;

    }
    return 0;
}
