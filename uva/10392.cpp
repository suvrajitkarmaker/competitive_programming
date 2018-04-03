#include <bits/stdc++.h>
using namespace std;
bool s[1100000];
long long int a[1000000];
int l=1;
void siv()
{
    int m=1000000;
    for(int i=2; i<=m; i+=2)
        s[i]=1;
    for(int i=3; i*i<=m; i+=2)
    {
        if(s[i]==0)
        {
            for(int j=i*i; j<=m; j*=i)
                s[j]=1;
        }
    }
    a[0]=2;
    for(int i=3; i<=m; i+=2)
    {
        if(s[i]==0)
            a[l++]=i;
    }
}
void fac(long long int x)
{
    for(int i=0; i<l && a[i]*a[i]<=x; i++)
    {
        if(x%a[i]==0)
        {
            while(x%a[i]==0)
            {
                cout<<"    "<<a[i]<<endl;
                x/=a[i];
            }
        }
    }
    if(x>1)
        cout<<"    "<<x<<endl;

    printf("\n");
}
int main()
{
    siv();

    long long int x;
    while(cin>>x)
    {
        if(x<0)
            break;
        fac(x);
    }
}
