#include <bits/stdc++.h>
using namespace std;
double p,q,r,s,t,u;
double fn(double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
void bi()
{
    double lo=0.0,hi=1.0,mid;
    while((lo+0.00000001)<=hi)
    {
        mid=(lo+hi)/2.0;

        if(fn(mid)>0.0000 && fn(mid)<0.00005)
        {
            printf("%0.4lf\n",mid);
            return;
        }
        if(fn(mid)>0)
            lo=mid;
        else
            hi=mid;
    }
    printf("No solution\n");
}
int main()
{
    while(scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u)!=EOF)
    {
        if(p==0 && q==0 && r==0 && s==0 && t==0 && u==0)
            printf("0.0000\n");
        else
            bi();
    }
}
