#include <bits/stdc++.h>
using namespace std;
int main()
{
    int te;
    double c,f,C,F;
    scanf("%d",&te);
    for(int i=0;i<te;i++)
    {
        scanf("%lf %lf",&c,&f);
        F=((9.0/5.0)*c)+32.0;
        F=f+F;
        C=((F-32.0)*5.0)/9.0;
        printf("Case %d: %0.2lf\n",i+1,C);
    }
}
