#include <bits/stdc++.h>
using namespace std;
#define inf 2147483647
int main()
{
    char c,s[100000];
    double a,b;
    while(gets(s))
    {
        printf("%s\n", s);
        sscanf(s, "%lf %c %lf", &a, &c, &b);
        if(a>inf)
            puts("first number too big");
        if(b>inf)
            puts("second number too big");
        if(c=='+' && a+b>inf)
            puts("result too big");
        if(c=='*' && a*b>inf)
            puts("result too big");
    }
}
