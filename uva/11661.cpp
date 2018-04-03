#include <bits/stdc++.h>
using namespace std;
char a[2100000];
int main()
{
    int m,mi,j,t;
    while(scanf("%d",&m))
    {
        if(m==0)
            break;
        scanf("%s",a);
        t=0;
        for(int i=0; i<m; i++)
        {
            if(a[i]=='Z')
            {
                t=1;
                break;
            }
        }
        if(t==1)
            printf("0\n");
        else
        {
            mi=9999999;
            t=0;
            for(int i=0; i<m; i++)
            {
                if(a[i]=='D')
                {
                    j=i;
                    i+=1;
                    while(a[i]!='R'&&a[i]=='.'&&i<m)
                        i++;

                    if(a[i]=='R'&&abs(i-j)<mi)
                        mi=abs(i-j);

                    i-=1;
                }
                else if(a[i]=='R')
                {
                    j=i;
                    i+=1;
                    while(a[i]!='D'&&a[i]=='.'&&i<m)
                        i++;

                    if(a[i]=='D'&&abs(i-j)<mi)
                        mi=abs(i-j);

                    i-=1;
                }
            }
            printf("%d\n",mi);
        }
    }
}
