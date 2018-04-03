#include <bits/stdc++.h>
using namespace std;
vector<string>s;
int main()
{
    char s[150][150];
    int i=0,ma=0;
    while(gets(s[i]))
    {
        if(strlen(s[i])>ma)
            ma=strlen(s[i]);
        i++;

    }
    int k=0,d=0;
    while(1)
    {
        for(int j=i-1; j>=0; j--)
        {

            if(k>=strlen(s[j]))
                printf(" ");
            else
                printf("%c",s[j][k]);
        }
        printf("\n");
        k++;
        if(k==ma)
            break;
    }
}
