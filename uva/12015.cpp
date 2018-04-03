#include <bits/stdc++.h>
using namespace std;
char s[20][110];
int main()
{
    int t;
    scanf("%d",&t);
    for(int l=1; l<=t; l++)
    {
        int d,ma=-1,a[110];
        for(int i=0; i<10; i++)
        {
            scanf("%s %d",s[i],&a[i]);
            if(a[i]>ma)
                ma=a[i];
        }
        printf("Case #%d:\n",l);
        for(int i=0; i<10; i++)
        {
            if(a[i]==ma)
                printf("%s\n",s[i]);
        }
    }
}
