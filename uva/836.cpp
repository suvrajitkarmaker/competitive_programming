#include<bits/stdc++.h>
using namespace std;
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int n,te;
    scanf("%d",&te);
    for(int t=1; t<=te; t++)
    {
        char s[1000];
        int a[270][270],ro=0;
        scanf("%s",s);
        n=strlen(s);
        for(int j=0; j<n; j++)
        {
            if(s[j]=='0')
                a[0][j]=0;
            else
                a[0][j]=1;
        }
        for(int i=1;i<n;i++)
        {
            scanf("%s",s);
            for(int j=0;j<n;j++)
            {
                if(s[j]=='0')
                    a[i][j]=0;
                else
                    a[i][j]=1;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i>0)
                    a[i][j]+=a[i-1][j];
                if(j>0)
                    a[i][j]+=a[i][j-1];
                if(i>0 && j>0)
                    a[i][j]-=a[i-1][j-1];
            }
        }
        int sm,mx=0,xx;
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
                        xx=((k-i)+1)*((l-j)+1);
                        if(xx==sm)
                            mx=max(mx,sm);
                    }
                }
            }
        }
        if(t>1)
            printf("\n");
        printf("%d\n",mx);

    }
}
