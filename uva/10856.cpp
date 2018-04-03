#include <bits/stdc++.h>
using namespace std;
bool s[31700];
int a[31700];
int res[10001000];
void siv()
{
    int sq=sqrt(31700),n=31700,i,j;
    for(i=4;i<=n;i+=2)
        s[i]=1;
    for(i=3;i<=sq;i+=2)
    {
        if(s[i]==0)
        {
            for(j=i*i;j<=n;j+=i)
                s[j]=1;
        }
    }
    s[1]=1;
    for(i=2,j=0;i<=n;i++)
    {
        if(s[i]==0)
            a[j++]=i;
    }
}
int fac(int n)
{
    int c=0;
    for(int i=0;a[i]*a[i]<=n;i++)
    {
        if(n%a[i]==0)
        {
            while(n%a[i]==0)
            {
                n/=a[i];
                c++;
            }
        }
    }
    if(n>1)
    {
        c++;
    }
    return c;

}
int xx[100001000];
int main()
{
    siv();
    for(int i=2;i<=2703663;i++)
    {
        res[i]=res[i-1]+fac(i);
        xx[res[i]]=i;
    }

    int n,c1,i=1;
    while(scanf("%d",&n) && n>=0)
    {
        //c1=binary(n);
        c1=xx[n];
        if(n==0)
            printf("Case %d: 0!\n",i);
        else if(c1==0)
            printf("Case %d: Not possible.\n",i);
        else
            printf("Case %d: %d!\n",i,c1);
        i++;
    }
}

