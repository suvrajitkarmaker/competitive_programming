#include <bits/stdc++.h>
using namespace std;
int ct(int n)
{
    int co=0;
    while(n>0)
    {
        n/=10;
        co++;
    }
    return co;
}
int main()
{
    char s[1000000];
    int n,m,tp;
    while(scanf("%s",s))
    {
        if(strcmp(s,"END")==0)
            break;
        int c1=2;
        n=strlen(s);
        m=ct(n);
        while(n!=m)
        {
            c1++;
            n=m;
            m=ct(n);
        }
        if(strcmp(s,"1")==0)
            printf("1\n");
        else
        printf("%d\n",c1);
    }
}
