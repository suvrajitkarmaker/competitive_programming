#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,d,x=0;
    char s[10000];
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%s",s);
        x=0;
        d=s[0]-65;
        d=d*26+(s[1]-65);
        d=d*26+(s[2]-65);
        x=x*10+(s[4]-48);
        x=x*10+(s[5]-48);
        x=x*10+(s[6]-48);
        x=x*10+(s[7]-48);
        if(abs(x-d)<=100)
            printf("nice\n");
        else
            printf("not nice\n");
    }
}
