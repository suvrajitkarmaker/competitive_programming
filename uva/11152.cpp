#include <bits/stdc++.h>
using namespace std;
#define pi 2*acos(0.0)
double outcircle(double a,double b,double c)
{
    double red=(a*b*c)/(sqrt((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c)));
    return pi*red*red;
}
double triangle(double a,double b,double c)
{
    double s=(a+b+c)/2;

    return sqrt(s*(s-a)*(s-b)*((s-c)));
}
double incircle(double a,double b,double c)
{
    double red=(2*triangle(a,b,c))/(a+b+c);

    return pi*red*red;
}
int main()
{
    double a,b,c,y,r,bu;
    while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF)
    {
        y=outcircle(a,b,c)-triangle(a,b,c);
        r=incircle(a,b,c);
        bu=triangle(a,b,c)-r;
        printf("%.4lf %.4lf %.4lf\n",y,bu,r);
    }
}
