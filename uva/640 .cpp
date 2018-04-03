#include <bits/stdc++.h>
using namespace std;
int a[1100000],fi=1000000;
int rec(int n)
{
    int x=n;
    while(x>0)
    {
        n+=x%10;
        x/=10;
    }
    return n;
}
int main()
{
    for(int i=1; i<=fi; i++)
    {
        if(a[i]==0)
        {
            int t=rec(i);
            while(t<=fi)
            {
                if(a[t]==1)
                    break;
                a[t]=1;
                t=rec(t);
            }
        }
    }
    for(int i=1; i<=fi; i++)
    {
        if(a[i]==0)
            printf("%d\n",i);
    }
}
