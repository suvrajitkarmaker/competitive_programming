#include <bits/stdc++.h>
using namespace std;
bool s[31700];
int a[31700];
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
int phi(int n)
{
    int ret=n,i;
    for(i=0; a[i]*a[i]<=n; i++)
    {
        if(n%a[i]==0)
        {
            while(n%a[i]==0)
            {
                n/=a[i];
            }
            ret-=ret/a[i];
        }
    }
    if(n>1)
    {
        ret-=ret/n;
    }
    return ret;
}
int res[5000000];
int main()
{
    siv();
    res[1]=1;
    for(int i=2;i<=50001;i++)
    {
        res[i]=res[i-1]+(2*phi(i));
    }
    long long int l;
    while(1)
    {
        cin>>l;
        if(l==0)
            break;
        printf("%d\n",res[l]);
    }
}

