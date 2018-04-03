#include <bits/stdc++.h>
using namespace std;
char s[110000],r[110000];
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        int d=strlen(s),t,p,x=0,i;
        strcpy(r,s);
        for(i=0; i<d; i++)
        {
            t=i;
            p=d-1;
            while(1)
            {
                if(t>=p)
                {
                    x=1;
                    break;
                }
                if(s[t]==s[p])
                {
                    t++;
                    p--;

                }
                else
                    break;
            }
            if(x==1)
                break;
        }
        r[i]='\0';
        reverse(r,r+i);
        printf("%s%s\n",s,r);
    }
}
