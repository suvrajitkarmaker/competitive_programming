#include <bits/stdc++.h>
using namespace std;
vector<long long int>a;
int main()
{
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(2);
    long long int x,n;
    for(int i=5; i<=44721362; i++)
    {
        x=i-3;
        x+=(x*(x+1))/2;
        a.push_back(x);
    }
    int j=1;
    while(scanf("%lld",&n))
    {
        if(n==0)
            break;
        vector<long long int>::iterator low,up;
        up = upper_bound (a.begin(),a.end(),n);
        if(a[up - a.begin()-1]==n)
            printf("Case %d: %d\n",j,up-a.begin()-1);
        else
            printf("Case %d: %d\n",j,up-a.begin());
        j++;
    }
}
