#include <bits/stdc++.h>
using namespace std;
int t_s(int x,int y)
{
    char a[100000],b[100000];
    int i=0;
    while(x>0)
    {
        a[i++]=(x%10)+48;
        x/=10;
    }
    a[i++]=48;
    a[i]='\0';
    reverse(a,a+i);
    i=0;
    while(y>0)
    {
        b[i++]=(y%10)+48;
        y/=10;
    }
    b[i++]=48;
    b[i]='\0';
    reverse(b,b+i);
    printf("%s-",a);
    int t=0;
    for(int j=0; j<i; j++)
    {
        if(a[j]!=b[j] && t==0)
            t=1;
        if(t==1)
        {
            printf("%c",b[j]);
        }
    }
    printf("\n");
}
int main()
{
    int t,j,n=1;
    while(scanf("%d",&t))
    {
        if(t==0)
            break;
        int a[t],x=0;
        for(int i=0; i<t; i++)
        {
            scanf("%d",&a[i]);
        }
        printf("Case %d:\n",n++);
        for(int i=0; i<t; i++)
        {
            x=a[i];
            j=i;
            while(x+1==a[i+1]&& (i+1)<t)
            {
                x=a[i+1];
                i++;
            }
            if(a[j]<x)
                t_s(a[j],x);
            else
                printf("0%d\n",a[j]);
        }
        printf("\n");
    }
}
