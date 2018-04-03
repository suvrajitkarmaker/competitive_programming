#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[1100000];
    int xx=1;
    while(scanf("%s",s)!=EOF)
    {
        printf("Case %d:\n",xx++);
        int t,n,m;
        scanf("%d",&t);
        for(int i=0; i<t; i++)
        {
            scanf("%d %d",&n,&m);
            if(n>m)
                swap(n,m);
            int c=0;
            for(int j=n; j<m; j++)
            {
                if(s[j]!=s[j+1])
                {
                    c=1;
                    break;
                }
            }
            if(c==0)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
}
