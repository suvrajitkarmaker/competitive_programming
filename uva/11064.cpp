#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
#define gcd3(x,y,z)                __gcd(__gcd(x,y),z)
#define INF                     LLONG_MAX
#define inf                     LONG_MAX
#define PI                      (2.0*acos(0.0))
#define Log(b,x)                (log(x)/log(b))
#define all(x)                  (x).begin(), (x).end()
#define Unique(x)               sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x)          to_string(x)
#define stringtoint(x)          stoll(x)
#define valid(nx,ny,row,col)    nx>0 && nx<=row && ny>0 && ny<=col
#define CLR(x,y)                memset(x,y,sizeof(x));
#define MAX 100100000
#define eps 1e-15
int s[1000000],a[1000000],l=1;
void siv()
{
    int n=1000000;
    for(int i=4;i<=n;i+=2)
        s[i]=1;

    for(int i=3;i*i<=n;i+=2)
    {
        if(s[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                s[j]=1;
            }
        }
    }
    a[0]=2;
    for(int i=3;i<=n;i+=2)
    {
        if(s[i]==0)
            a[l++]=i;
    }
}
int phi(int n)
{
    int re=n;
    for(int i=0;i<l && a[i]*a[i]<=n;i++)
    {
        if(n%a[i]==0)
        {
            while(n%a[i]==0)
            {
                n/=a[i];
            }
            re-=re/a[i];
        }
    }
    if(n>1)
    {
        re-=re/n;
    }
    return re;
}
int nod(int n)
{
    int re=1,ct;
    for(int i=0;i<l && a[i]*a[i]<=n;i++)
    {
        if(n%a[i]==0)
        {
            ct=1;
            while(n%a[i]==0)
            {
                n/=a[i];
                ct++;
            }
            re*=ct;
        }
    }
    if(n>1)
    {
        re*=2;
    }
    return re;
}
int main()
{
    siv();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",n-(phi(n)+nod(n))+1);
    }

}
