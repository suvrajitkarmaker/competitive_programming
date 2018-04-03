#include <bits/stdc++.h>
using namespace std;
void mod(string s)
{
    long long int l=s.size(),m;
    m=s[0]-48;
    for(int i=1; i<l-1; i++)
    {
        m=m*2+(s[i]-48);
        m%=131071;
    }
    if(m==0)
        printf("YES\n");
    else
        printf("NO\n");
}
int main()
{
    string s,x;
    while(cin>>s)
    {
        int d=s.size();
        if(s[d-1]=='#')
        {
            x=x+s;
            mod(x);;
            x.clear();
        }
        else
            x=x+s;
    }
}
