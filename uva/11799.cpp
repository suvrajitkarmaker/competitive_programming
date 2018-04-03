#include <bits/stdc++.h>
using namespace std;
int main()
{
     int n,x,t,ma;
     scanf("%d",&t);
     for(int i=0;i<t;i++)
     {
         ma=0;
         scanf("%d",&n);
         for(int j=0;j<n;j++)
         {
             scanf("%d",&x);
             if(x>ma)
                ma=x;
         }
         printf("Case %d: %d\n",i+1,ma);
     }

}
