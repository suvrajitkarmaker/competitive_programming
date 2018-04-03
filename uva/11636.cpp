#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,j=1;
    while(1)
    {
        cin>>n;
        if(n<0)
            break;
        int c=0;
        for(int i=1;i<n;i*=2)
            c++;
        printf("Case %d: %d\n",j++,c);
    }
}
