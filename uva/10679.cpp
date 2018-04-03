#include <bits/stdc++.h>
using namespace std;
unsigned long long int x[1000000],base=107;
unsigned long long int ha(string a)
{
    unsigned long long int value=0;
    for(int i=0; i<a.length(); i++)
    {
        value=(value*base)+a[i];
        x[i]=value;
    }
}
int main()
{
    string a,b;
    int t;
    while(scanf("%d",&t)!=EOF)
    {
        cin>>a>>b;
        unsigned long long int y,i,j,value=0,mul=1,re[100000];
        for(int i=0; i<a.length(); i++)
        {
            value=(value*base)+a[i];
            mul*=base;
        }
        ha(b);
        for(i=b.length()-1,j=0; i>=t-1; i--)
        {
            if((i-t)<0)
                y=x[i];
            else
                y=x[i]-(x[i-t]*mul);
            if(y==value)
                re[j++]=i-t+1;
        }
        if(j==0)
            cout<<endl<<endl;
        else
        {
            sort(re,re+j);
            for(i=0; i<j; i++)
                cout<<re[i]<<endl;
        }
    }
}
