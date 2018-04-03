#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m))
    {
        if(n==1 && m==1)
            break;
        int l1=0,l2=1,r1=1,r2=0,c1=1,c2=1;
        while(1)
        {
           if(c1==n && c2==m)
                break;
            if(c1*m>=c2*n)
            {
                printf("L");
                r1=c1;
                r2=c2;
                c1+=l1;
                c2+=l2;
            }
            else
            {
                printf("R");
                l1=c1;
                l2=c2;
                c1+=r1;
                c2+=r2;

            }
        }
        printf("\n");
    }
}
