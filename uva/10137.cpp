#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        double a[n],sum=0.0;

        for(int i=0;i<n;i++)
        {
            scanf("%lf",&a[i]);
            sum+=a[i];
        }
        sort(a,a+n,greater<double>());
        double s=0.0,av=sum/double(n);
        for(int i=0;i<n;i++)
        {
            if(a[i]>av)
                s+=a[i]-av;
        }
        printf("%lf\n",s);
    }
}
