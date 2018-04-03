#include <bits/stdc++.h>
using namespace std;
int x[100000];
int main()
{
    int z,i,m,l,c,tt,j=1;
    while(scanf("%d %d %d %d",&z,&i,&m,&l))
    {
        if(z==0 && i==0 && m==0 && l==0)
            break;
        memset(x,0,sizeof(x));
        c=1;
        tt=l;
        x[l]=1;
        while(1)
        {
            l=((z*l)+i)%m;
            if(x[l]==1)
                break;
            x[l]=1;
            c++;

        }
        if(tt!=l)
            c--;
        printf("Case %d: %d\n",j++,c);
    }
}

