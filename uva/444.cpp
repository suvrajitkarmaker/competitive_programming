#include <bits/stdc++.h>
using namespace std;
string ch_de(char s[])
{
    int l=strlen(s),t;
    string rs;
    for(int i=l-1; i>=0; i--)
    {
        t=s[i];
        while(t>0)
        {
            rs+=(t%10)+48;
            t/=10;
        }
    }
    return rs;
}
string de_ch(char s[])
{
    int t,l=strlen(s);
    string x;
    for(int i=0; i<l; i+=2)
    {
        t=s[i]-48;
        t=(t*10)+(s[i+1]-48);
        if(t>=10 && t<=12)
        {
            t=(t*10)+(s[i+2]-48);
            i++;
        }
        x+=t;
    }
    return x;
}
int main()
{
    char s[1000000];
    char c;
    while(gets(s))
    {
        int l=strlen(s);
        if(s[0]>='0' && s[0]<='9')
        {
            reverse(s,s+l);
            //cout<<s<<endl;
            cout<<de_ch(s)<<endl;
        }
        else
        {
            cout<<ch_de(s)<<endl;
        }
    }
}
