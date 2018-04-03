#include <bits/stdc++.h>
using namespace std;
int main()
{
    int te;
    cin>>te;
    for(int i=0;i<te;i++)
    {
        int n;
        cin>>n;
        int a[n];
        for(int j=0;j<n;j++)
            cin>>a[j];
        int h=0,l=0;
        for(int j=0;j<n-1;j++)
        {
            if(a[j]<a[j+1])
                h++;
            if(a[j]>a[j+1])
                l++;
        }
        printf("Case %d: %d %d\n",i+1,h,l);
    }
}
