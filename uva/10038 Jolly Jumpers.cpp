#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int main()
{
    int n,i,x,k;
    while(scanf("%d",&n)==1)
    {
        int a[n],t=0,b[n],j;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }

        for(i=0,j=0; i<n-1; i++)
        {
            x=a[i]-a[i+1];
            if(x<0)
                x=x*(-1);
            if(x>=1 && x<=n-1)
                b[j++]=x;
            else
            {
                t=1;
                break;
            }
        }
        sort(b,b+j);
        for(i=0;i<j-1;i++)
        {
            if(b[i]==b[i+1])
                t=1;
        }
        if(t==0)
            printf("Jolly\n");
        else if(t==1)
            printf("Not jolly\n");
    }
    return 0;
}
