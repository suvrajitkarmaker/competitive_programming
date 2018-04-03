#include <bits/stdc++.h>
using namespace std;
int cuberoot(int x)
{
    int i=0;
    while(1)
    {
        if((i*i*i)==x)
        {
            return i;
            break;
        }
        else if((i*i*i)>x)
        {
            return i+1;
            break;
        }
        i++;
    }
}
long long int cube(int x)
{
    return x*x*x;
}
int main()
{
    int t;
    while(scanf("%d",&t))
    {
        if(t==0)
            break;
        int i=1,d,c=1,y;
        long long int x;
        while(1)
        {
            x=t+cube(i);
            y=cuberoot(x);
            d=cube(y);
            if(x==d)
            {
                c=1;
                break;
            }
            else if(x>d)
            {
                c=0;
                break;
            }
            i++;
        }
        if(c==1)
            printf("%d %d\n",y,i);
        else if(c==0)
            printf("No solution\n");

    }
}
