#include <bits/stdc++.h>
using namespace std;
void mod(long long int n, string s)
{
    int l=s.size(),m=0;
    for(int i=0;i<l;i++)
    {
        m=((m*10)+(s[i]-48))%n;
    }
    printf("%d\n",m);
}
int main()
{
    string s;
    long long int n,t;
    scanf("%lld",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%lld",&n);
        cin>>s;
        mod(n,s);
    }
    return 0;
}
