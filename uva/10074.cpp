#include<bits/stdc++.h>
using namespace std;
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int n,m;
    while(scanf("%d %d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        int a[n+100][m+100],sum[n+100];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%d", &a[i][j]);
                if(a[i][j]==0)
                    a[i][j]=1;
                else
                    a[i][j]=-9999;
            }
        }
        int sm,mx=0,xx;
        for(int i=0; i<m; i++)
        {
            memset(sum,0,sizeof(sum));
            for(int j=i; j<m; j++)
            {
                int s=0;
                for(int k=0; k<n; k++)
                {
                    sum[k]+=a[k][j];
                    s+=sum[k];
                    if(s<sum[k])
                        s=sum[k];
                    mx=max(s,mx);
                }
            }
        }
        printf("%d\n",mx);
    }
}
