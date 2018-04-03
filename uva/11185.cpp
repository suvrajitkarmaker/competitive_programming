#include <bits/stdc++.h>
using namespace std;
vector<int>s;
int main()
{
    long long int n;
    while(scanf("%lld",&n))
    {
        s.clear();
        if(n<0)
            break;
            if(n==0)
                s.push_back(0);
        while(n>0)
        {
            s.push_back(n%3);
            n/=3;
        }
        for(int i=s.size()-1;i>=0;i--)
            printf("%d",s[i]);
        printf("\n");
    }
}
