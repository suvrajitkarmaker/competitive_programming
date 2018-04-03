#include <bits/stdc++.h>
using namespace std;
int a[510][510];
int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}
int main()
{
    int x[510];
    for(int k=2; k<=500; k++)
    {
        int sum=0;
        for(int i=1; i<k; i++)
        {
            for(int j=i+1; j<=k; j++)
            {
                if(a[i][j]!=0)
                    sum+=a[i][j];
                else if(a[j][i]!=0)
                    sum+=a[j][i];
                else
                {
                    a[i][j]=gcd(i,j);
                    sum+=a[i][j];
                }
            }
        }
        x[k]=sum;
    }
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        printf("%d\n",x[n]);
    }
}
