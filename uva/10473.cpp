#include <bits/stdc++.h>
using namespace std;
void D_H(char s[])
{
    long long int l=strlen(s),t=0;
    for(int i=0; i<l; i++)
        t=(t*10)+(s[i]-48);

    long long int i=0,x;
    char a[10000];
    while(t>0)
    {
        x=t%16;
        if(x>=10 && x<=15)
            a[i++]=x+55;
        else
            a[i++]=x+48;
        t/=16;
    }
    a[i]='\0';
    reverse(a,a+i);
    printf("0x%s\n",a);
}
void H_D(char s[])
{
    int l=strlen(s);
    long long int t=0;
    for(int i=2,j=l-3; i<l; i++,j--)
    {
        if(s[i]>='A' && s[i]<='F')
            t+=(s[i]-55)*pow(16,j);
        else if(s[i]>='a' && s[i]<='f')
            t+=(s[i]-87)*pow(16,j);
        else
            t+=((s[i]-48)*pow(16,j));

    }
    printf("%lld\n",t);
}
int main()
{
    char s[10000];
    while(scanf("%s",s))
    {
        getchar();
        if(s[0]=='-')
            break;
        if(s[0]=='0'&&s[1]=='x')
            H_D(s);
        else
            D_H(s);
    }
}
