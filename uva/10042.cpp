#include <bits/stdc++.h>
using namespace std;
bool s[1100000];
long long int a[1000000],l=1;
void siv()
{
    int n=1000000;
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
int degitsum(int x)
{
    int sum=0;
    while(x>0)
    {
        sum+=x%10;
        x/=10;
    }
    return sum;
}

int sm(int x)
{
    int sum1=degitsum(x),sum2=0,y=x;
    for(int i=0; i<l && (a[i]*a[i])<=x; i++)
    {
        if(x%a[i]==0)
        {
            int t=degitsum(a[i]);

            while(x%a[i]==0)
            {
                sum2+=t;
                x/=a[i];
            }
        }
    }
    if(x>1)
    {
        sum2+=degitsum(x);
    }
    if(sum1==sum2 && x!=y)
        return 1;
    else
        return 0;

}
int main()
{
    siv();

    int t,n,d;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        scanf("%d",&n);
        n++;
        while(sm(n)==0)
            n++;
        printf("%d\n",n);
    }
}
