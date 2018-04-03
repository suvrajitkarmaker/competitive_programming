#include <bits/stdc++.h>
using namespace std;
int a[100000];
int ite[100000];
int temp[100000];
vector<long long int>s;
int ssum(int n)
{
    s.clear();
    int t=n,c=1;
    s.push_back(n);
    while(1)
    {
        long long int d,sum=0;
        while(t>0)
        {
            d=t%10;
            sum+=d*d;
            t/=10;
        }

        t=sum;
        s.push_back(sum);
        if(t==1)
        {
            if(n!=1)
                c++;
                int tt=s.size();
            for(int i=0; i<tt; i++)
            {
                a[s[i]]=1;
                ite[s[i]]=c-i;
            }
            return 1;
        }
        if(t==4||t==16||t==20||t==37||t==42||t==58||t==89||t==145)
        {
            for(int i=0; i<s.size(); i++)
            {
                a[s[i]]=2;
            }
            return 2;
        }
        c++;
    }
}
int cal()
{
    for(int i=1; i<=99999; i++)
    {
        if(a[i]==0)
        {
            int  t=ssum(i);
        }
    }
}
int main()
{
    cal();
    int n,m,c=0;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(c>0)
            printf("\n");
        for(int i=n;i<=m;i++)
            if(a[i]==1)
            printf("%d %d\n",i,ite[i]);
        c++;
    }

}
