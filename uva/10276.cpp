#include <bits/stdc++.h>
using namespace std;
int main()
{
     int t,n,d;
     scanf("%d",&t);
     for(int i=0;i<t;i++)
     {
         scanf("%d",&n);
         if(n%2==0)
         {
             printf("%d\n",(n*(n/2))+(n-1));
         }
         else
         {
             d=n/2;
             printf("%d\n",(n*(d+1))+d);
         }
     }

}
