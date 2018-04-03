#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,te=1;
    while(1)
    {
        cin>>n;
        if(n==0)
            break;
        int sum=0,a[n],t,c=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        t=sum/n;
        for(int i=0; i<n; i++)
        {
            if(a[i]<t)
                c+=t-a[i];
        }
        printf("Set #%d\n",te++);
        printf("The minimum number of moves is %d.\n\n",c);
    }
}
