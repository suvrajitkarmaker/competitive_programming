#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    char s[100000];
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        int n,sum=0,x;
        scanf("%d",&n);
        int a[n];
        for(int j=0; j<n; j++)
        {
            scanf("%s",s);
            if(strcmp(s,"LEFT")==0)
            {
                sum+=-1;
                a[j]=-1;
            }
            else if(strcmp(s,"RIGHT")==0)
            {
                sum+=1;
                a[j]=1;
            }
            else
            {
                scanf("%s %d",s,&x);
                sum+=a[x-1];
                a[j]=a[x-1];
            }
        }
        printf("%d\n",sum);
    }
}
