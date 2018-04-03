#include <bits/stdc++.h>
using namespace std;
int m,a[500];
int bac(int p,int c,int s)
{
    if(c==2)
    {
        printf("%d\n",s);
    }
    bac(p+1,c,s);
    if(s+a[p]<=m)
        bac(p+1,c+1,s+a[p]);
}
int main()
{
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    bac(0,1,0);
}
