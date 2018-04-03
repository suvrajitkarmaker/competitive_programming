#include <bits/stdc++.h>
using namespace std;

long long int res[10000];
int main()
{
    res[0]=0;
    res[1]=2;
    res[2]=3;
    for(int i=3; i<55; i++)
    {
        res[i]=res[i-1]+res[i-2];
    }
    int n,m;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&m);
        printf("Scenario #%d:\n%lld\n",i+1,res[m]);
        printf("\n");
    }
}
