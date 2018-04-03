#include <bits/stdc++.h>
using namespace std;
int used[1000],number[1000],j=0,te,co,re[1000000];
void permutation(int a,int l)
{
    int i;
    if(a==5)
    {
        int x=0;
        for(i=0; i<5; i++)
            x=(x*10)+number[i];
        if(x>999)
            re[j++]=x;
        return;
    }
    for(i=l; i<=9; i++)
    {
        if(used[i]==0)
        {
            used[i]=1;
            number[a]=i;
            permutation(a+1,l);
            used[i]=0;
        }
    }
    return;
}
int chek(int n, int m)
{
    int x[10],t=0,p=n,q=m;
    memset(x,0,sizeof(x));
    if(n<10000 && x[0]==0)
        x[0]=1;
    while(n>0)
    {
        if(x[n%10]==0)
        {
            x[n%10]=1;
        }
        else
        {
            t=1;
            break;
        }
        n/=10;
    }
    if(m<10000 && x[0]==0)
        x[0]=1;
    else if(m<10000 && x[0]==1)
        t=1;
    if(t==0)
    {
        while(m>0)
        {
            if(x[m%10]==0)
            {
                x[m%10]=1;
            }
            else
            {
                t=1;
                break;
            }
            m/=10;
        }
    }
    if(t==0)
    {
        co++;
        if(p<10000)
            printf("0%d / %d = %d\n",p,q,te);
        else if(q<10000)
            printf("%d / 0%d = %d\n",p,q,te);
        else if(p <10000 && q<10000)
            printf("0%d / 0%d = %d\n",p,q,te);
        else
            printf("%d / %d = %d\n",p,q,te);
        return 1;
    }
    else
        return 0;
}
int main()
{
    permutation(0,0);
    int c=0;
    while(scanf("%d",&te))
    {
        if(te==0)
            break;
        if(c>0)
            printf("\n");
        co=0;
        for(int i=0; i<j; i++)
        {
            if(re[i]%te==0 && (re[i]/te)>999)
            {
                chek(re[i],re[i]/te);
            }
        }
        if(co==0)
            printf("There are no solutions for %d.\n",te);
        c++;
    }
}
