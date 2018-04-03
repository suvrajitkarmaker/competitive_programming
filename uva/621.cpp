#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,d;
    scanf("%d",&t);
    char x[100000];
    for(int i=0; i<t; i++)
    {
        scanf("%s",x);
        d=strlen(x);
        if(strcmp(x,"1")==0||strcmp(x,"4")==0||strcmp(x,"78")==0)
            printf("+\n");
        else if(x[d-2]=='3'&&x[d-1]=='5')
            printf("-\n");
        else if(x[0]=='9'&&x[d-1]=='4')
            printf("*\n");
        else
            printf("?\n");
    }
}
