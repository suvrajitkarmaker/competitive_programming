#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(1)
    {
        cin>>n;
        if(n==0)
            break;
        int a[n],i;
        for(i=0; i<n; i++)
            cin>>a[i];
        sort(a,a+n);
        for(i=0; i<n; i++)
        {
            if(i==n-1)
                printf("%d\n",a[i]);
            else
                printf("%d ",a[i]);
        }
    }
    return 0;
}
