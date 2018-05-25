#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
#define Unique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x) to_string(x)
#define stringtoint(x) stoll(x)
#define valid(nx,ny,row,col) nx>=0 && nx<row && ny>=0 && ny<col
int n,m,k;
int fn(int x)
{
    int nn=n+(n-2);
    int mo,dd;
    if(x%nn==0)
        mo=nn;
    else
        mo=x%nn;

    if(mo>n)
    {
        dd=mo-n;
        mo=n-dd;
    }
    return mo;
}
int ch(int x)
{
    while(x)
    {
        if(x%10==7)
            return 0;
        x/=10;
    }
    return 1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int p,ct;
    while(scanf("%d %d %d",&n,&m,&k))
    {
        if(n==0 && m==0 && k==0)
            break;
        ct=0;
        for(int i=1;; i++)
        {
            p=fn(i);
            if(p==m && ( ch(i)==0 ||i%7==0))
            {
                ct++;
                //cout<<i<<" ";
            }
            if(ct==k)
            {
                printf("%d\n",i);
                break;
            }
        }
    }

}
