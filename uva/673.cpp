#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int main()
{
    char a[1000];
    int n,i,j,k;
    scanf("%d",&n);
    getchar();
    for(i=0; i<n; i++)
    {
        gets(a);
        int x=0,c=0;
        for(j=0; j<strlen(a); j++)
        {
            if(a[j]==' ')
                c++;
        }
        if(c==strlen(a))
        {
            printf("Yes\n");
            continue;
        }
        for(j=0; j<strlen(a); j++)
        {
            k=j;
            if(a[k]==')')
            {
                if(a[k-1]=='(')
                {
                    a[k]='0';
                    a[k-1]='0';

                }
                else
                {
                    while(1)
                    {
                        k--;
                        if(k==-1)
                        {
                            break;
                        }
                        if(a[k]=='(')
                        {
                            a[j]='0';
                            a[k]='0';
                            break;
                        }
                        else if(a[k]=='0');
                        else
                        {
                            break;
                        }
                    }
                }
            }
            else if(a[k]==']')
            {
                if(a[k-1]=='[')
                {
                    a[k]='0';
                    a[k-1]='0';
                }
                else
                {
                    while(1)
                    {
                        k--;
                        if(k==-1)
                        {
                            break;
                        }
                        if(a[k]=='[')
                        {
                            a[j]='0';
                            a[k]='0';
                            break;
                        }
                        else if(a[k]=='0');
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        for(j=0; j<strlen(a); j++)
        {
            if(a[j]!='0')
            {
                x=1;
                break;
            }
        }
        if(x==0)
            printf("Yes\n");
        else if(x==1)
            printf("No\n");
    }
    return 0;
}
