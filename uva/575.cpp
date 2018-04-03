#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(1)
    {
        cin>>s;
        if(s.length()==1&&s[0]=='0')
            break;
        long long int sum=0,t=1;
        for(int i=s.length()-1; i>=0; i--)
        {
            t*=2;
            sum+=(s[i]-48)*(t-1);
        }
        cout<<sum<<endl;
    }
}
