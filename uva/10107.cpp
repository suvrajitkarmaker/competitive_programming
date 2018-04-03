#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,s,c=0,a[11000];
    while(cin>>n)
    {
        if(c==0)
            a[c++]=n;
        else
        {
            int i;
            for(i=c-1;a[i]>n;i--)
            {
                a[i+1]=a[i];
            }
            a[i+1]=n;
            c++;
        }
        t=c/2;
        s=a[t];
        if(c%2==0)
            s=((a[t]+a[t-1])/2);
        cout<<s<<endl;
    }
}
