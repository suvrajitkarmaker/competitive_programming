#include <bits/stdc++.h>
using namespace std;
int main()
{
    int te;
    double n,g,r,pi=acos(-1.0);
    scanf("%d",&te);
    for(int i=0;i<te;i++)
    {
        scanf("%lf",&n);
        g=(6*n)/10;
        g=g*n;
        r=(2*n)/10;
        r=r*r*pi;
        printf("%0.2lf %0.2lf\n",r,g-r);
    }
}
