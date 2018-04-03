#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    long long int x,i,j,m,y;
    int te;
    scanf("%d",&te);
    for(int k=0; k<te; k++)
    {
        scanf("%lld",&x);
        memset(a,0,sizeof(a));
        y=x;
        m=1;
        if(y==0)
            printf("10\n");
        else if(y>=1 && y<=9)
            printf("%lld\n",y);
        else
        {
            for(i=9,j=0; i>=2; i--)
            {
                if(x%i==0)
                {
                    m=m*i;
                    a[j++]=i;
                    x=x/i;
                    i=10;
                }
            }
            sort(a,a+j);
            if(m==y)
            {
                for(i=0; i<j-1; i++)
                    printf("%d",a[i]);
                printf("%d\n",a[j-1]);
            }
            else
                printf("-1\n");
        }
    }
}
