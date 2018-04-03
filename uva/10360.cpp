#include <bits/stdc++.h>
using namespace std;
int res[1025][1025];
int main()
{
    int t,d,n,p,q;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        scanf("%d %d",&d,&n);
        int x,y,z;
        int mx=0;
        memset(res,0,sizeof(res));
        for(int j=0; j<n; j++)
        {
            scanf("%d %d %d",&x,&y,&z);
            int st1=x-d;
            if(st1<0)
                st1=0;
            int fi1=x+d;
            if(fi1>1024)
                fi1=1024;
            int st2=y-d;
            if(st2<0)
                st2=0;
            int fi2=y+d;
            if(fi2>1024)
                fi2=1024;
            for(int k=st1; k<=fi1; k++)
            {
                for(int l=st2; l<=fi2; l++)
                {

                    res[k][l]+=z;
                }
            }
        }
        for(int j=0; j<=1024; j++)
        {
            for(int k=0; k<=1024; k++)
            {

                if(res[j][k]>mx)
                {
                    p=j;
                    q=k;
                    mx=res[j][k];
                }
            }
        }
        printf("%d %d %d\n",p,q,mx);
    }
}
