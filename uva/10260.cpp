#include <bits/stdc++.h>
using namespace std;
int check(char c)
{
    if(c=='B'||c=='F'||c=='P'||c=='V')
        return 1;
    else if(c=='C'||c=='G'||c=='J'||c=='K'||c=='Q'||c=='S'||c=='X'||c=='Z')
        return 2;
    else if(c=='D'||c=='T')
        return 3;
    else if(c=='L')
        return 4;
    else if(c=='M'||c=='N')
        return 5;
    else if(c=='R')
        return 6;
    else
        return 0;
}
int main()
{
    char s[1000];
    while(scanf("%s",s)!=EOF)
    {
        int d=strlen(s),x;
        for(int i=0; i<d; i++)
        {
            if(check(s[i])==0)
                continue;
            if(check(s[i])==check(s[i+1])&&(i+1)<d)
            {
                printf("%d",check(s[i]));
                while(check(s[i])==check(s[i+1])&&(i+1)<d)
                    i++;
            }
            else
                printf("%d",check(s[i]));
        }
        printf("\n");
    }
}
