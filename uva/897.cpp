#include <bits/stdc++.h>
using namespace std;
bool s[11000000];
int a[10000000],l=1;
void siv()
{
    int n=1000;
    s[2]=0;
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
int aa[200],k,used[40],number[40],c1,c2;
void permutation(int at, int n)
{
    int i;
    if(at==n+1)
    {
        c1++;
        int tt=0;
        for(i=1; i<=n; i++)
            tt=(tt*10)+aa[number[i]];
        if(s[tt]==0)
            c2++;
        return;
    }
    for(i=1; i<=n; i++)
    {
        if(used[i]==0)
        {
            used[i]=1;
            number[at]=i;
            permutation(at+1,n);
            used[i]=0;
        }
    }
    return;
}

int permu(int x)
{
    memset(aa,0,sizeof(aa));
    k=1;
    c1=0;
    c2=0;
    while(x>0)
    {
        aa[k++]=x%10;
        x/=10;
    }
    permutation(1,k-1);
    if(c1==c2)
        return 1;
    else
        return 0;
}
int po(int n)
{
    int x=1;
    while(n>0)
    {
        x*=10;
        n/=10;
    }
    return x;
}
int main()
{
    siv();

    int n,x,t;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        if(n>=999)
        {
            printf("0\n");
            continue;
        }
        x=po(n);
        n++;
        t=0;
        if(s[n]==0 && n>0)
            n=n-1;
        int j=upper_bound(a, a+l, n) - a;
        while(a[j]<x)
        {

            if(permu(a[j])==1)
            {
                t=1;
                break;
            }
            j++;
        }
        if(t==0)
            printf("0\n");
        else
            printf("%d\n",a[j]);
    }
}
