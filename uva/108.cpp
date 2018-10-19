#include<bits/stdc++.h>
using namespace std;


int main()
{

    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[n][n];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                scanf("%d",&a[i][j]);
                if(i>0)
                    a[i][j]+=a[i-1][j];
                if(j>0)
                    a[i][j]+=a[i][j-1];
                if(i>0 && j>0)
                    a[i][j]-=a[i-1][j-1];
            }
        int sm,mx=-99999999;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                for(int k=i; k<n; k++)
                {
                    for(int l=j; l<n; l++)
                    {
                        sm=a[k][l];
                        if(i>0)
                            sm-=a[i-1][l];
                        if(j>0)
                            sm-=a[k][j-1];
                        if(i>0 && j>0)
                            sm+=a[i-1][j-1];
                        mx=max(mx,sm);
                    }
                }
            }
        }
        printf("%d\n",mx);
    }
}
