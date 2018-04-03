#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,j,b,y;
    double x;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        double sum=0.0,av,c;
        for(j=0; j<12; j++)
        {
            scanf("%lf",&x);
            sum=sum+x;
        }
        av=sum/12.0;
        printf("%d $",i);
        if(av<=999999.0 && av>999.0)
        {
            int a = av/1000.0;
            printf("%d,",a);
            av = fmod(av,1000.0);
        }
        printf("%.2lf\n",av);
    }
    return 0;
}
