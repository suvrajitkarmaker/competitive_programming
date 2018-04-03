#include <bits/stdc++.h>
using namespace std;
char x[5500][10000];
char re[10000];
char* bigintsum(char *a,char *b)
{
    int al=strlen(a);
    int bl=strlen(b);
    reverse(a,a+al);
    reverse(b,b+bl);
    int l=al;
    if(bl>al)
        l=bl;
    a[al]='0';
    b[bl]='0';
    int t=0,j=0;
    for(int i=0; i<l; i++)
    {
        t+=(a[i]-48)+(b[i]-48);
        if(t>9)
        {
            re[j++]=(t%10)+48;
            t=t/10;
        }
        else
        {
            re[j++]=t+48;
            t=0;
        }
    }
    if(t>0)
    {
        re[j++]=t+48;
        re[j]='\0';
    }
    else
        re[j]='\0';
    reverse(re,re+j);
    return re;
}
int main()
{
    char x1[10000],x2[10000];
    memset(x1,'0',sizeof(x1));
    memset(x2,'0',sizeof(x2));
    strcpy(x[0],"0");
    strcpy(x[1],"1");
    for(int i=2; i<=5000; i++)
    {
        strcpy(x1,x[i-1]);
        strcpy(x2,x[i-2]);
        strcpy(x[i],bigintsum(x1,x2));
    }
    int n;
    while(cin>>n)
    {
        printf("The Fibonacci number for %d is %s\n",n,x[n]);
    }
    return 0;
}
