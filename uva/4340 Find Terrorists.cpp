#include <bits/stdc++.h>
using namespace std;
bool s[1100000];
long long int a[1000000],l=0;
void siv()
{
    int n=1000000;
    for(int i=4; i<=n; i+=2)
    {
        s[i]=1;
    }
    for(int i=3; i*i<=n; i+=2)
    {
        if(s[i]==0)
        {
            for(int j=i*i; j<=n; j+=i)
                s[j]=1;
        }
    }
    s[1]=1;
    for(int i=2; i<=n; i++)
    {
        if(s[i]==0)
        {
            a[l++]=i;
        }
    }
}
int pf(int n)
{
    int mu=1;
    for(int i=0;a[i]*a[i]<=n;i++)
    {
        if(n%a[i]==0)
        {
            int c=0;
            while(n%a[i]==0)
            {
                c++;
                n/=a[i];
            }
            c++;
            mu*=c;
        }
    }
    if(n>1)
    {
        mu*=2;
    }
    if(s[mu]==0)
        return 0;
    else
        return 1;
}
bool re[10000000];
int main()
{
    siv();
    re[0]=1;
    for(int i=1;i<=10000;i++)
    {
        re[i]=pf(i);
    }
    int t,n,m;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&n,&m);
        int te=0;
        for(int j=n;j<=m;j++)
        {
            if(re[j]==0)
            {
                if(te==0)
                {
                    printf("%d",j);
                }
                else
                    printf(" %d",j);
                te++;
            }
        }
        if(te==0)
            printf("-1\n");
        else
            printf("\n");
    }
}
