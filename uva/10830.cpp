#include <bits/stdc++.h>
using namespace std;
bool s[1000000];
long long int a[1000000];
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
    for(int i=2, j=0; i<=n; i++)
    {
        if(s[i]==0)
        {
            a[j++]=i;
        }
    }
}
int power_sum(int n,int p)
{
    int sum=0;
    for(int i=0; i<=p; i++)
        sum+=pow(n,i);
    return sum;
}
int sod(int n)
{
    int m=n,sum=1;
    for(int i=0; a[i]*a[i]<=n; i++)
    {
        if(n%a[i]==0)
        {
            int c=0;
            while(n%a[i]==0)
            {
                c++;

                n/=a[i];
            }
            sum*=power_sum(a[i],c);

        }
    }
    if(n>1)
    {
        sum*=power_sum(n,1);
    }
    return sum-(1+m);
}
int main()
{
    siv();
    //cout<<sod(2)<<endl;
    int n,sum=0;
    for(int i=2;i<=100;i++)
    {
        sum+=sod(i);
        cout<<sum<<endl;
     }
     cout<<"dsa";
}
