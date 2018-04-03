#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;

        int t,sum=0;
        long long int x=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&t);
            sum+=t;
            x+=abs(sum);
        }
        printf("%lld\n",x);
    }
}
