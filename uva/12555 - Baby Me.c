#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,n,l;
    double x,y,sum;
    char a[20];
    scanf("%d%*c",&n);
    for(i=0; i<n; i++)
    {
        scanf("%lf",&x);
        gets(a);
        sum=x*0.5;
        for(j=0; j<strlen(a); j++)
        {
            if(a[j]>='0' && a[j]<='9')
            {
                y=(a[j]-48)*0.05;
                sum=sum+y;
            }
        }
        printf("Case %d: %g\n",i+1,sum);
    }
    return 0;
}
