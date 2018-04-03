#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a[50];
    while(1)
    {
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if(a[0]==0 && a[1]==0 &&a[2]==0)
            break;
        if(((a[0]*a[0])+(a[1]*a[1]))==(a[2]*a[2]))
            cout<<"right"<<endl;
        else
            cout<<"wrong"<<endl;
    }
}
