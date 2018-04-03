#include <bits/stdc++.h>
using namespace std;
int res[10000];
void fac(int m,int b)
{
    int co,tm1;
    for(int i=2; i<=m && i<=b; i++)
    {
        if(m%i==0)
        {
            while(m%i==0)
            {
                res[i]++;
                m/=i;
            }
        }
    }
}
int degit(int n,int b)
{
    int x;
    double sum=0;
    for(int i=1; i<=n; i++)
    {
        sum+=log10(i);
    }
    sum/=log10(b);
    return floor(sum+1e-9) + 1;
}

int zero(int n,int b)
{
    memset(res,0,sizeof(res));
    for(int i=2; i<=n; i++)
    {
        fac(i,b);
    }
    int zero=0,bb;
    while(1)
    {
        bb=b;
        int i;
        for(i=2; i<=bb; i++)
        {
            while(res[i]>0 && bb%i==0)
            {
                res[i]--;
                bb/=i;
            }
        }
        if(bb==1)
            zero++;
        else
            break;
    }
    return zero;
}
int main()
{
    int n,b;
    while(scanf("%d %d",&n,&b)!=EOF)
    {
        printf("%d %d\n",zero(n,b),degit(n,b));
    }
}
