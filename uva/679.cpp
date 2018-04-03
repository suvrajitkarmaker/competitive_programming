#include <bits/stdc++.h>
using namespace std;
int b_n(int l,int h, int k)
{
    int mid;
    while(l<h)
    {
        mid=(l+h)/2;
        if(k%2==0)
        {
            l=mid+1;
            k/=2;
        }
        else
        {
            h=mid;
            k/=2;
            k++;
        }
    }
    return h;
}
int main()
{
    int t,d,k,s,l,h;
    int po[50];
    po[0]=1;
    for(int i=1; i<=20; i++)
        po[i]=po[i-1]*2;
    while(scanf("%d",&t))
    {
        if(t==-1)
            break;
        for(int i=0; i<t; i++)
        {
            scanf("%d %d",&d,&k);
            d--;
            s=po[d];
            l=s;
            h=s+s-1;
            printf("%d\n",b_n(l,h,k));
        }
    }
}
