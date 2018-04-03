#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a,b,c,s,x;
    while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF)
    {

        s=(a+b+c)/2.0;
        x=(4.0/3.0)*sqrt(s*(s-a)*(s-b)*(s-c));
        if(x>0)
            printf("%0.3lf\n",x);
        else
            printf("-1.000\n");
    }
}
