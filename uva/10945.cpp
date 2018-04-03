#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[100000];
    while(gets(s))
    {
        if(strcmp(s,"DONE")==0)
            break;

        int j=0,l=strlen(s);
        char a[100000],b[100000];
        for(int i=0; i<l; i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                b[j]=s[i];
                a[j++]=s[i];

            }
            else if(s[i]>='A'&&s[i]<='Z')
            {
                b[j]=s[i]+32;
                a[j++]=s[i]+32;
            }
        }
        a[j]='\0';
        b[j]='\0';
        reverse(b,b+j);
        if(strcmp(a,b)==0)
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");

    }
}
