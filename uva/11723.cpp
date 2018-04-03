#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i=1,x,p;
    while(scanf("%d %d",&n,&m)&& n && m)
    {
        x=n-m;
        p=x/m;
        if(x%m!=0)
            p++;
        if(m>n)
            p=0;
        if(p>26)
            printf("Case %d: impossible\n",i);
        else
            printf("Case %d: %d\n",i,p);
        i++;
    }
}
