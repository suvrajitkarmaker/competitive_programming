#include <bits/stdc++.h>
using namespace std;
bool s[100000000];
long long int a[10000000],l=0;
void siv()
{
    int n=10000000;
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
int isprime(int n)
{
    if(n<=10000000)
        return s[n];
    for(int i=0; i<l && a[i]*a[i]<=n; i++)
    {
        if(n%a[i]==0)
            return 1;
    }
    return 0;
}
bool precal[11000];
int res[100000];
int main()
{
    siv();
    for(int i=0; i<=10000; i++)
        precal[i]=isprime((i*i)+i+41);
    res[0]=1;
    for(int i=1; i<=10000; i++)
    {
        if(precal[i]==0)
            res[i]=res[i-1]+1;
        else
            res[i]=res[i-1];
    }
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        /*int c=0;
        for(int i=n; i<=m; i++)
        {
            if(precal[i]==0)
                c++;
        }*/
        double x=((res[m]-res[n-1])*100.0)/double(m-n+1);
        printf("%0.2lf\n",x+0.000000001);
    }
}
