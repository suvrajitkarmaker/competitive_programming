#include <bits/stdc++.h>
using namespace std;
bool s[10000000];
long long int a[700000],l=1;
void siv()
{
    int n=1000000;
    s[1]=1;
    for(int i=4; i<=n; i+=2)
        s[i]=1;
    for(int i=3; i*i<=n; i+=2)
    {
        if(s[i]==0)
        {
            for(int j=i*i; j<=n; j+=i)
                s[j]=1;
        }
    }
    a[0]=2;
    for(int i=3; i<=n; i+=2)
    {
        if(s[i]==0)
            a[l++]=i;
    }
}
void check(long long int n)
{
    long long int x,c,f=0,nn=n;
    n=abs(n);
    for(long long int i=2; i*i<=n; i++)
    {
        x=n;
        c=0;
        while(x%i==0)
        {
            x/=i;
            c++;
        }
        if((x==1 && nn>0)||(x==1 && nn<0 && c%2==1))
        {
            f=1;
            break;
        }
    }

    if(f==1)
        printf("%d\n",c);
    else
        printf("1\n");
}

int main()
{
    //siv();
    long long int n;
    while(scanf("%lld",&n) && n!=0)
        check(n);
}
