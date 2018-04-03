#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[1000000],c;
    int n,x[200];
    scanf("%d",&n);
    getchar();
    for(int i=0; i<n; i++)
    {
        gets(a);
        int d=strlen(a);
        memset(x,0,sizeof(x));
        for(int j=0; j<d; j++)
        {
            if(a[j]>='A' && a[j]<='Z')
            {
                x[a[j]+32]++;
            }
            else if(a[j]>='a'&&a[j]<='z')
            {
                x[a[j]]++;
            }
        }
        int m=0;
        for(int j=97;j<=122;j++)
        {
            if(x[j]>m)
                m=x[j];
        }
        for(int j=97;j<=122;j++)
        {
            if(m==x[j])
                printf("%c",j);
        }
        printf("\n");
    }
}
