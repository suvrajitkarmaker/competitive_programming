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
                s[j]=0;
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
    return sum;
}
void space_print(int n)
{
    int c=0;;
    while(n>0)
    {
        c++;
        n/=10;
    }
    for(int i=1; i<=(5-c); i++)
        printf(" ");
}
int main()
{
    siv();
    int n,d,i=0;
    while(cin>>n)
    {
        if(i==0)
        printf("PERFECTION OUTPUT\n");
        if(n==0)
        {
            printf("END OF OUTPUT\n");
            break;
        }
        d=sod(n)-n;
        if(d==n)
        {
            space_print(n);
            printf("%d  PERFECT\n",n);
        }
        else if(d<n)
        {
            space_print(n);
            printf("%d  DEFICIENT\n",n);
        }
        else
        {
            space_print(n);
            printf("%d  ABUNDANT\n",n);
        }
        i++;
    }
}
