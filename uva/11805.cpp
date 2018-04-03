#include <bits/stdc++.h>
using namespace std;
void h_f(int n,int m)
{
    int sum=0,i=0;
    while(n>0 || m>0)
    {
        if((n%2==1 && m%2==0)||(m%2==1 && n%2==0))
        {
            sum+=pow(2,i);
        }
        n/=2;
        m/=2;
        i++;
    }
    printf("%d\n",sum);
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        h_f(n,m);
    }
}
