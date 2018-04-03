#include <bits/stdc++.h>
using namespace std;
int carry_count(char a[],char b[])
{
    int x=strlen(a),y=strlen(b);
    int c=0,co=0;
    if(x>=y)
    {
        for(int i=x-1,j=y-1; i>=0; i--,j--)
        {
            if(j<0)
                c=(c+(a[i]-48))/10;
            else
                c=(c+(a[i]-48)+(b[j]-48))/10;
            if(c>0)
                co++;

        }
    }
    else
    {
        for(int i=y-1,j=x-1; i>=0; i--,j--)
        {
            if(j<0)
                c=(c+(b[i]-48))/10;
            else
                c=(c+(b[i]-48)+(a[j]-48))/10;
            if(c>0)
                co++;
        }
    }
    if(co==0)
        printf("No carry operation.\n");
    else if(co==1)
        printf("%d carry operation.\n",co);
    else
        printf("%d carry operations.\n",co);
}
int main()
{
    char a[100000],b[100000];
    while(scanf("%s %s",a,b))
    {
        if(strcmp(a,"0")==0 && strcmp(b,"0")==0)
            break;
        carry_count(a,b);
    }
}
