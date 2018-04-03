#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[1000000];
    char c;
    while(gets(s))
    {
        //getchar();
        int l=strlen(s);
        string tt;
        for(int i=0; i<l; i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
            {
                string x;
                while(i<l &&((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')))
                {
                    x+=s[i];
                    i++;
                }
                x+="ay";
                tt+=x;
               x.clear();
            }
            else if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
            {
                string x;
                char c=s[i];
                i++;
                while(i<l &&((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')))
                {
                    x+=s[i];
                    i++;
                }
                x+=c;
                x+="ay";
                tt+=x;
                x.clear();
            }
            tt+=s[i];
        }
        cout<<tt<<endl;
        tt.clear();
    }
}
