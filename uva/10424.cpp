#include <bits/stdc++.h>
using namespace std;
int onedegit(int n)
{
    if(n<10)
        return n;
    int sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    onedegit(sum);
}
int main()
{
    string n,m;
    while(getline(cin,n))
    {
        getline(cin,m);
        int sum1=0,sum2=0;
        for(int i=0; i<n.size(); i++)
        {
            if(n[i]>='a'&&n[i]<='z')
                sum1+=n[i]-96;
            if(n[i]>='A'&&n[i]<='Z')
                sum1+=n[i]-64;
        }
        for(int i=0; i<m.size(); i++)
        {
            if(m[i]>='a'&&m[i]<='z')
                sum2+=m[i]-96;
            if(m[i]>='A'&&m[i]<='Z')
                sum2+=m[i]-64;
        }
        double x,y,d;
        x=double(onedegit(sum1));
        y=double(onedegit(sum2));
        if(y>x)
            swap(x,y);
        d=(y*100.0)/x;
        char c='%';
        printf("%0.2lf %c\n",d,c);
    }
}
