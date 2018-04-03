#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        int sum=0,t=0;
        while(n>=3)
        {
            sum+=n/3;
            n=(n/3)+(n%3);
            if((n+1)%3==0&&t==0)
            {
                n+=1;
                t=1;
            }
        }
        printf("%d\n",sum);
    }
}
