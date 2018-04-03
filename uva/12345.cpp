#include <bits/stdc++.h>
using namespace std;
set<int>s;
int xx[10000000];
int main()
{
    int n,m,x,co,y;
    char c;
    scanf("%d %d",&n,&m);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
    {
        scanf(" %c %d %d",&c,&x,&y);
        if(c=='M')
            a[x]=y;
        else
        {
           co=0;
           for(int j=x;j<y;j++)
           {
               xx[a[j]]++;
           }
           for(int j=x;j<y;j++)
           {
               if(xx[a[j]]==1)
                co++;
               xx[a[j]]--;
           }
           printf("%d\n",co);
        }


    }
}
