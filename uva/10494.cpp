#include <bits/stdc++.h>
using namespace std;
void mod(long long int n, char s[], char c)
{
    long long int l=strlen(s),m=0,p=0,j=0,t=0;
    char x[1000000];
    for(int i=0; i<l; i++)
    {
        p=((m*10)+(s[i]-48))/n;
        if(p>0)
            t=1;
        if(t==1)
            x[j++]=p+48;
        m=((m*10)+(s[i]-48))%n;
    }
    x[j]='\0';
    if(j==0)
    {
        x[0]=48;
        x[1]='\0';
    }
    if(c=='/')
        printf("%s\n",x);
    else if(c=='%')
        printf("%lld\n",m);
}
int main()
{
    char s[1000000],c;
    long long int n,t;
    while(scanf("%s %c %lld",s,&c,&n)!=EOF)
    {
        mod(n,s,c);
    }
    return 0;
}
