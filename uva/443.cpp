#include <bits/stdc++.h>
using namespace std;
long long int tw[50],th[50],fi[50],se[50],res[100000000],t=0,x;
void precal()
{
    for(int i=0; i<=20; i++)
    {
        for(int j=0; j<=20; j++)
        {
            for(int k=0; k<=20; k++)
            {
                for(int l=0; l<=30; l++)
                {
                    //x=pow(2.0,l)*pow(3.0,k)*pow(5.0,j)*pow(7.0,i)ACline;
                    x=tw[l]*th[k]*fi[j]*se[i];
                    if(x>0)
                        res[t++]=x;
                }
            }
        }
    }
    sort(res,res+t);
}
void pre(int n)
{
    int tt=n%100;
    if(tt>=10 && tt<=20)
        printf("The %dth humble number is %lld.\n",n,res[n-1]);
    else if(n%10==1)
        printf("The %dst humble number is %lld.\n",n,res[n-1]);
    else if(n%10==2)
        printf("The %dnd humble number is %lld.\n",n,res[n-1]);
    else if(n%10==3)
        printf("The %drd humble number is %lld.\n",n,res[n-1]);
    else
        printf("The %dth humble number is %lld.\n",n,res[n-1]);
}
int main()
{
    tw[0]=1;
    th[0]=1;
    fi[0]=1;
    se[0]=1;
    for(int i=1; i<=30; i++)
         tw[i]=tw[i-1]*2;
    for(int i=1; i<=20; i++)
    {
         th[i]=th[i-1]*3;
         fi[i]=fi[i-1]*5;
         se[i]=se[i-1]*7;
    }
    precal();
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        pre(n);
    }
}
