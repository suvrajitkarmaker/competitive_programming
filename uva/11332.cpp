#include <bits/stdc++.h>
using namespace std;
int rec(long long int s)
{
    long long int sum=0;
    while(s>9)
    {
        sum+=s%10;
        s/=10;
    }
    sum+=s;
    if(sum<10)
        return sum;
    else
        rec(sum);
}
int main()
{
    long long int n;
    while(cin>>n)
    {
        if(n==0)
            break;
        cout<<rec(n)<<endl;
    }
}
