#include <bits/stdc++.h>
using namespace std;
bool s[10000000];
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
                s[j]=1;
        }
    }
}
int rev(int n)
{
    int x=0;
    while(n>0)
    {
        x=(x*10)+(n%10);
        n/=10;
    }
    return x;
}
int main()
{
    siv();
    int x,d;
    while(scanf("%d",&x)!=EOF)
    {
        d=rev(x);
        if(s[x]==1)
            printf("%d is not prime.\n",x);
        else if((s[x]==0 && s[d]==1)||(s[x]==0 && x==d))
            printf("%d is prime.\n",x);
        else if(s[x]==0 && s[d]==0)
            printf("%d is emirp.\n",x);
    }
}
