#include <bits/stdc++.h>
using namespace std;
int binary_decimal(char s[])
{
    int l=strlen(s),m=0;
    for(int i=0,j=l-1; i<l; i++,j--)
        m+=(s[i]-48)*pow(2,j);
    return m;
}
int main()
{
    char s[100000],p[100000];
    int te;
    scanf("%d",&te);
    for(int k=1; k<=te; k++)
    {
        scanf("%s %s",s,p);
        int x,y,t=0;
        x=binary_decimal(s);
        y=binary_decimal(p);
        for(int i=2; i*i<=y; i++)
        {
            if(x%y==0)
            {
                t=1;
                break;
            }
            if(y%i==0)
            {
                if(x%i==0||x%(y/i)==0)
                    t=1;
            }
        }
        if(t==1)
            printf("Pair #%d: All you need is love!\n",k);
        else
            printf("Pair #%d: Love is not all you need!\n",k);
    }
}
