#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n,m,c,co,x;
   while(scanf("%d %d",&n,&m)!=EOF)
   {
       co=0;
       for(int i=0;i<n;i++)
       {
           c=0;
           for(int j=0;j<m;j++)
           {
               scanf("%d",&x);
               if(x>0)
                c++;
           }
           if(c==m)
            co++;
       }
       printf("%d\n",co);
   }
}
