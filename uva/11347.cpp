#include <bits/stdc++.h>
using namespace std;
bool s[100000000];
long long int a[100000000];
void siv()
{
    int n=1000;
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
    for(int i=2, j=0; i<=n; i++)
    {
        if(s[i]==0)
        {
            a[j++]=i;
        }
    }
}
//map<long long int,int>mp;
long long int mp[1000];
vector<long long int>ss;
void nod(int n)
{
    for(int i=0; a[i]*a[i]<=n; i++)
    {
        if(n%a[i]==0)
        {
            if(mp[a[i]]==0)
                ss.push_back(a[i]);
            while(n%a[i]==0)
            {
               mp[a[i]]++;
                n/=a[i];
            }
        }
    }
    if(n>1)
    {
        if(mp[n]==0)
                ss.push_back(n);
            mp[n]++;
    }
}
int main()
{
    siv();
    char st[100000];
    int n,te,k;

    scanf("%d",&te);
    for(int j=1;j<=te;j++)
    {
        //mp.clear();
        memset(mp,0,sizeof(mp));
        ss.clear();
        scanf("%d%s",&n,st);
        k=strlen(st);
        while(n>0)
        {
            nod(n);
            n-=k;
        }
        long long int mul=1,f1=0;
        for(int i=0;i<ss.size();i++)
        {
            mul*=mp[ss[i]]+1;
            if(mul>1000000000000000000)
            {
                f1=1;
                break;
            }
        }
        if(f1==1)
            printf("Case %d: Infinity\n",j);
        else
            printf("Case %d: %lld\n",j,mul);
    }
}
