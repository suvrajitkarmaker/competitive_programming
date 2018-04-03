#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,sum=0,x;
    char c[10000];
    cin>>n;
    for(i=0;i<n;i++)
    {
        scanf("%s",c);
        if(strcmp(c,"donate")==0)
        {
            scanf("%d",&x);
            sum=sum+x;
        }
        else if(strcmp(c,"report")==0)
            printf("%d\n",sum);
    }
    return 0;
}
