#include <bits/stdc++.h>
using namespace std;
int m,n;
int fn(int p,int q)
{
    int d1=m*m + n*n;
    int d2=p*m + n*q;
    int d3=p*n - m*q;
    int x=p*p + q*q;
    if(d1%x==0 && d2%x==0 && d3%x==0)
        return 0;

    return 1;
}
int main()
{
    int x,y,te;
    scanf("%d",&te);
    while(te--)
    {
        scanf("%d %d",&m,&n);
        int ct=0;
        for(int i=-145;i<=145;i++)
        {
            for(int j=-145;j<=145;j++)
            {
                if(!i && !j)continue;

                if(fn(i,j)==0)
                    ct++;
            }
        }
        //cout<<ct<<endl;
        if(ct==8)
            printf("P\n");
        else
            printf("C\n");
    }
}
