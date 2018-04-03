#include <bits/stdc++.h>
using namespace std;
void h_f(long long int n)
{
    int i=0,c=0;
    long long int m=n;
    char s[10000];
    while(n>0)
    {
        if(n%2==1)
            c++;
        s[i++]=(n%2)+48;
        n/=2;
    }
    s[i]='\0';
    reverse(s,s+i);
    printf("The parity of %s is %lld (mod 2).\n",s,c);
}
int main()
{
    long long int n;
    while(scanf("%lld",&n))
    {
        if(n==0)
            break;
        h_f(n);
    }
}
