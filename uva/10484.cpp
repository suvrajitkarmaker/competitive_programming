#include <bits/stdc++.h>
using namespace std;
bool s[1100];
long long int a[1000],l=0;
int pre[150][150];
void siv()
{
    int n=150;
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
    int x=n;
    for(int i=0; i<l; i++)
    {
        pre[x][a[i]]=pre[x-1][a[i]];
    }
    for(int i=0; i<l && a[i]*a[i]<=n; i++)
    {
        if(n%a[i]==0)
        {
            while(n%a[i]==0)
            {
                n/=a[i];
                pre[x][a[i]]++;
            }
        }
    }
    if(n>1)
    {
        pre[x][n]++;
    }
}
int tmp[100];
int main()
{
    siv();
    pre[1][1]=1;
    for(int i=1; i<=100; i++)
    {
        pf(i);
    }
    long long int n,m;
    while(scanf("%lld %lld",&n,&m))
    {
        if(n==0 && m==0)
            break;
        if(n==0 &&abs(m)==1)
        {
            printf("1\n");
            continue;
        }
        m=abs(m);
        memset(tmp,0,sizeof(tmp));
        long long int tp=m;
        for(int i=0; i<l; i++)
            tmp[a[i]]=pre[n][a[i]];
        int c1=0;
        for(int i=0; i<l && a[i]*a[i]<=tp; i++)
        {
            if(tp%a[i]==0)
            {
                while(tp%a[i]==0)
                {
                    tp/=a[i];
                    if(tmp[a[i]]<1)
                    {
                        c1=1;
                        break;
                    }
                    tmp[a[i]]--;
                }
            }
            if(c1==1)
                break;
        }
        if(c1==1||tp>100)
        {
            printf("0\n");
            continue;
        }
        if(tp>1)
            tmp[tp]--;
        long long int ml=1;
        for(int i=0; i<l; i++)
            ml*=tmp[a[i]]+1;
        printf("%lld\n",ml);
    }
}
