#include <bits/stdc++.h>
using namespace std;
bool s[1100000];
int a[1000000],l=1,mxn=-1;
void siv()
{
    int n=1000000;
    s[2]=0;
    for(int i=4; i<=n; i+=2)
        s[i]=1;
    for(int i=3; i*i<=n; i+=2)
    {
        if(s[i]==0)
        {
            for(int j=i*i; j<=n; j+=i)
                s[j]=1;
        }
    }
    a[0]=2;
    for(int i=3; i<=n; i+=2)
    {
        if(s[i]==0)
            a[l++]=i;
    }
    for(int i=1; i<l; i++)
    {
        if((a[i]-a[i-1])>mxn)
            mxn=(a[i]-a[i-1]);
    }
}
int main()
{
    siv();
    int t,n,m,up,lo;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        scanf("%d %d",&n,&m);
        int res[mxn+10],p=n,q=m;
        memset(res,0,sizeof(res));
        if(s[n]==0 && n>0)
            n=n-1;
        lo = upper_bound(a, a+l, n) - a;
        if(s[m]==0)
            m++;
        up = lower_bound(a, a+l, m) - a;
        up--;
        int xx,mx=-1;
        for(int j=lo; j<up; j++)
        {
            xx=a[j+1]-a[j];
            res[xx]++;

        }
        for(int j=0; j<=mxn; j++)
        {
            if(res[j]>mx)
                mx=res[j];
        }
        int c=0,result;
        for(int j=0; j<=mxn; j++)
        {
            if(res[j]==mx)
            {
                c++;
                result=j;
            }
        }
        int itr=up-lo+1;
        if(c>1 || itr<2)
            printf("No jumping champion\n");
        else
            printf("The jumping champion is %d\n",result);
    }
}
