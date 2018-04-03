#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[100000];
    while(gets(s))
    {
        map<char,int>c;

        int l=strlen(s),ma=0;
        for(int i=0; i<l; i++)
        {
            c[s[i]]++;
            if(c[s[i]]>ma&&((s[i]>='a'&&s[i]<'z')||(s[i]>='A'&&s[i]<'Z')))
                ma=c[s[i]];
        }
        for(int i=0; i<26; i++)
        {
            if(ma==c[i+65])
                printf("%c",i+65);
        }
        for(int i=0; i<26; i++)
        {
            if(ma==c[i+97])
                printf("%c",i+97);
        }
        cout<<" "<<ma<<endl;
    }
}
