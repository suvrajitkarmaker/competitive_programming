#include<bits/stdc++.h>
using namespace std;
int a[200][200];
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int n,m,te;
    scanf("%d",&te);
    while(te--)
    {
        scanf("%d",&n);
        int mx=-999999999,sum[n+100],a[n*2+10][n*2+10];
        memset(a,0,sizeof(a));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                scanf("%d", &a[i][j]);
                a[i+n][j]=a[i][j+n]=a[i+n][j+n]=a[i][j];
            }
        }
        for(int i=0; i<n*2; i++)
        {
            for(int j=0; j<n*2; j++)
            {
                if(i>1)
                    a[i][j]+=a[i-1][j];
                if(j>1)
                    a[i][j]+=a[i][j-1];
                if(i>1 && j>1)
                    a[i][j]-=a[i-1][j-1];
            }
        }
        for(int x=1; x<=n; x++)
        {
            for(int y=1; y<=n; y++)
            {
                for(int i=x; i<x+n; i++)
                {
                    for(int j=y; j<y+n; j++)
                    {
                        int vl=a[i][j];
                        //mx=max(mx,vl);
                        if(x>1)
                            vl-=a[x-1][j];
                        if(y>1)
                            vl-=a[i][y-1];
                        if(x>1 && y>1)
                            vl+=a[x-1][y-1];
                        mx=max(mx,vl);
                    }
                }
            }
        }
        printf("%d\n",mx);
    }
}
