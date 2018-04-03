#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    while(cin>>n)
    {
        if(n<0)
            break;
        if(n==1)
            cout<<"0%"<<endl;
        else
            cout<<25*n<<"%"<<endl;
    }
}
