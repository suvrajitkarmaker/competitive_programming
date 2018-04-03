#include <bits/stdc++.h>
using namespace std;
bool s[1000000];
long long int a[1000000],li=1;
void siv()
{
    int n=2000;
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
    a[0]=2;
    for(int i=3; i<=n; i+=2)
    {
        if(s[i]==0)
        {
            a[li++]=i;
        }
    }
}
int use[10000000];
int res[10000000];
int pf(int x)
{
    int l=x;
    res[l]=res[l-1];

    for(int i=0; i<li && a[i]*a[i]<=x; i++)
    {
        if(x%a[i]==0)
        {
            while(x%a[i]==0)
            {
                x/=a[i];
                res[l]++;
            }
        }
    }
    if(x>1 )
    {
        res[l]++;
    }
}
int main()
{
    siv();
    res[0]=1;
    res[1]=1;
    res[2]=1;
    use[2]=1;
    for(int i=3; i<2800000; i++)
        pf(i);
    int te,n;
    scanf("%d",&te);
    for(int i=0; i<te; i++)
    {
        scanf("%d",&n);
        int lo=upper_bound(res,res+2800000,n)-res;
        printf("%d\n",lo);
    }

}
