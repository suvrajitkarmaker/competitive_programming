#include<bits/stdc++.h>
using namespace std;
bool res[41000];
int bas[]={1000000000,100000000,10000000,1000000,100000,10000,1000,100,10};
int kap(int n)
{
    int x=n*n,p,q;
    for(int i=0;i<9;i++)
    {
        p=x/bas[i];
        q=x%bas[i];
        if(p+q==n && p>0 && q>0)
            return 1;
    }
    return 0;
}
int print(int n,int m)
{
    int s=0;
    for(int i=n;i<=m;i++)
    {
        if(res[i]==1)
        {
            printf("%d\n",i);
            s=1;
        }
    }
    return s;
}
int main()
{
    for(int i=2;i<=40000;i++)
        res[i]=kap(i);
    int t,n,m;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&n,&m);
        printf("case #%d\n",i+1);
        if(print(n,m)==0)
            printf("no kaprekar numbers\n");
        if(i<t-1)
            printf("\n");
    }
}
