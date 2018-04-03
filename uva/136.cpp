#include <bits/stdc++.h>
using namespace std;
long long int phi(long long int n)
{
    while(n%2==0)
        n/=2;
    while(n%3==0)
        n/=3;
    while(n%5==0)
        n/=5;
    if(n==1)
        return 0;
    else
        return 1;
}
int main()
{
    /**    long long int i=1,c=1;
        while(1)
        {
            if(phi(i)==0)
            {
                if(c==1500)
                    break;
                c++;
            }
            i++;

        }
        printf("The 1500'th ugly number is %lld.\n",i);
    **/
    printf("The 1500'th ugly number is 859963392.\n");
}
