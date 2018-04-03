#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main()
{
    char b[50],a[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int n,m,i,j;
    while(scanf("%s",b)!=EOF)
    {
        int sum=0,x=0;
        for(i=0;i<strlen(b);i++)
        {
            for(j=0;j<52;j++)
            {
                if(b[i]==a[j])
                {
                    sum=sum+j+1;
                }
            }
        }
        for(i=2;(i*i)<sum;i++)
        {
            if(sum%i==0)
            {
                x=1;
                break;
            }
        }
        if(x==1)
            printf("It is not a prime word.\n");
        else
            printf("It is a prime word.\n");
    }
    return 0;
}
