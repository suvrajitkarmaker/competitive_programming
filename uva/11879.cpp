#include <bits/stdc++.h>
using namespace std;
int mul(string s)
{
    int mo=0;
    for(int i=0;i<s.size();i++)
    {
        mo=((mo*10)+s[i]-48);
        mo%=17;
    }
    if(mo==0)
        return 1;
    else
        return 0;
}
int main()
{
    string s;
    while(cin>>s)
    {
        if(s=="0")
            break;
        cout<<mul(s)<<endl;
    }
}
