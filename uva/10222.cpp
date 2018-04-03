#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[]= {"qwertyuiop[]asdfghjkl;'zxcvbnm,./1234567890-=\\"};
    string s;
    getline(cin,s);
    int l,l1;
    l=s.size();
    l1=strlen(a);
    for(int i=0; i<l; i++)
    {
        if(s[i]==' ')
        {
            printf(" ");
            continue;
        }
        if(s[i]>='A' &&s[i]<='Z')
            s[i]=s[i]+32;

        for(int j=0; j<l1; j++)
        {
            if(s[i]==a[j])
            {
                printf("%c",a[j-2]);
                break;
            }
        }
    }
    printf("\n");
}
