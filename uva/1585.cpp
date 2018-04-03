#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[10000];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        int d=strlen(s),sum=0,t;
        for(int i=0;i<d;i++)
        {
            t=1;
            while(s[i]!='X'&&i<d)
            {
                i++;
                sum+=t;
                t++;
            }
        }
        printf("%d\n",sum);
    }
}
