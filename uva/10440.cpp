#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        int n,t,m;
        scanf("%d %d %d",&n,&t,&m);
        int a[m],sum,x,dd;
        for(int j=0; j<m; j++)
            scanf("%d",&a[j]);
        if(m%n!=0)
        {
            sum=a[m%n-1];
            x=m/n;
            sum+=x*(2*t);
            sum+=t;
            dd=x+1;
        }
        else
        {
            sum=a[n-1];
            x=m/n;
            x--;
            sum+=x*(t*2);
            sum+=t;
            dd=m/n;
        }
        if((a[m-1]+t)>sum)
            sum=a[m-1]+t;
        printf("%d %d\n",sum,dd);

    }
}
