#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,t;
    while(1)
    {
        cin>>n;
        if(n==0)
            break;
        t=sqrt(n);
        if(t*t==n)
              cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
