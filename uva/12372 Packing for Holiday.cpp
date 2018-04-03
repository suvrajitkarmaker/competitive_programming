#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y,z,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x>>y>>z;
        if((x>=1 &&x<=20)&&(y>=1&&y<=20)&&(z>=1&&z<=20))
            printf("Case %d: good\n",i+1);
        else
            printf("Case %d: bad\n",i+1);
    }
    return 0;
}
