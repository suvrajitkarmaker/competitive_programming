#include <bits/stdc++.h>
using namespace std;
vector<int>a;
map<int,int>b;
int main()
{
    int n,i=0;
    while(scanf("%d",&n)!=EOF)
    {
        a.push_back(n);
        b[n]++;
        i++;
    }
    for(int j=0; j<i; j++)
    {
        if(b[a[j]]!=0)
        {
            printf("%d %d\n",a[j],b[a[j]]);
            b[a[j]]=0;
        }
    }
}
