#include <bits/stdc++.h>
using namespace std;
bool s[5001000];
int a[5001000],xx[5001000];
void siv()
{
    int n=5000000;
    for(int i=2;i<=n;)
    {
        if(s[i]==0)
        {
            a[i]+=i;
            for(int j=2*i;j<=n;j+=i)
            {
                s[j]=1;
                a[j]+=i;
            }
        }
        if(i==2)
            i++;
        else
            i+=2;
    }
    xx[1]=0;
    for(int i=2,j=2;i<=n;i++,j++)
    {
        if(s[a[i]]==0)
        {
            xx[j]=xx[j-1]+1;
        }
        else
           xx[j]=xx[j-1];
    }
}
int main()
{
    siv();
    int n,m;
    while(scanf("%d",&n) && n!=0)
    {
        scanf("%d",&m);
        printf("%d\n",xx[m]-xx[n-1]);
    }
}
