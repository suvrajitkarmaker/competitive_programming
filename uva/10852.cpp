#include <bits/stdc++.h>
using namespace std;
bool s[1000000];
long long int a[1000000],j=0;
void siv()
{
    int n=1000000;
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
            a[j++]=i;
        }
    }
}
int main()
{
    siv();
    int t,n;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        scanf("%d",&n);
        n=(n/2);
        int upper1 = upper_bound(a, a+j, n) - a;
        cout<<a[upper1]<<endl;
    }
}
