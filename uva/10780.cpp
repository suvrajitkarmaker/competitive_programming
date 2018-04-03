#include <bits/stdc++.h>
using namespace std;
bool s[51000];
long long int a[51000],l=1,k;
int res[1000000];
void siv()
{
    int sq=sqrt(75),n=75,i,j;
    for(i=4; i<=n; i+=2)
        s[i]=1;
    for(i=3; i<=sq; i+=2)
    {
        if(s[i]==0)
        {
            for(j=i*i; j<=n; j+=i)
                s[j]=1;
        }
    }
    s[1]=1;
    a[0]=2;
    for(i=3; i<=n; i+=2)
    {
        if(s[i]==0)
            a[l++]=i;
    }
}
int ct(int n,int m)
{
    int sum=0;
    while((n/m)>0)
    {
        sum+=n/m;
        n/=m;
    }
    return sum;
}
void fac(int m,int n)
{
    int co,tm1;
    for(int i=0; i<l && a[i]*a[i]<=m; i++)
    {
        if(m%a[i]==0)
        {
            tm1=ct(n,a[i]);
            co=0;
            while(m%a[i]==0)
            {
                co++;
                m/=a[i];
            }
            res[k++]=tm1/co;
        }
    }
    if(m>1)
    {
        tm1=ct(n,m);
        res[k++]=tm1;
    }
}
int main()
{
    siv();
    int n,m,t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        scanf("%d %d",&m,&n);
        k=0;
        memset(res,0,sizeof(res));
        fac(m,n);
        sort(res,res+k);
        if(res[0]==0||k==0)
            printf("Case %d:\nImpossible to divide\n",i);
        else
            printf("Case %d:\n%d\n",i,res[0]);
    }
}
