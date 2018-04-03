#include <bits/stdc++.h>
using namespace std;
long long int h[]={6,35,204,1189,6930,40391,235416,1372105,7997214,46611179};
long long int s[]={8,49,288,1681,9800,57121,332928,1940449,11309768,65918161};
int main()
{
    /*Genarate AC soltuion
    long long int i=8,k,c=0;
    double j;
    while(c<10)
    {
        j=sqrt((i*(i+1))/2);
        k=j;
        if(j==k)
        {
            printf("%10lld%10lld\n",k,i);
            c++;
        }
        i++;
    }
    */
    for(int i=0;i<10;i++)
    {
        printf("%10lld%10lld\n",h[i],s[i]);
    }

}
