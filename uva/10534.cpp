#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define gcd3(x,y,z)                __gcd(__gcd(x,y),z)
#define INF                     LLONG_MAX
#define inf                     LONG_MAX
#define PI                      (2.0*acos(0.0))
#define Log(b,x)                (log(x)/log(b))
#define all(x)                  (x).begin(), (x).end()
#define Unique(x)               sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x)          to_string(x)
#define stringtoint(x)          stoll(x)
#define valid(nx,ny,row,col)    nx>0 && nx<=row && ny>0 && ny<=col
#define CLR(x,y)                memset(x,y,sizeof(x));
#define MAX 100100000
#define eps 1e-15
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int v[n],p[n],l=0,LIS[n],LDS[n];
        CLR(p,0);
        CLR(LDS,0);
        CLR(LIS,0);
        for(int i=0;i<n;i++)
            scanf("%d",&v[i]);
        for(int i=0;i<n;i++)
        {
            int po=lower_bound(p,p+l,v[i])-p;
            p[po]=v[i];
            if(po==l)
                l++;
            LIS[i]=l;
        }
        reverse(v,v+n);
        l=0;
        CLR(p,0);
        for(int i=0;i<n;i++)
        {
            int po=lower_bound(p,p+l,v[i])-p;
            p[po]=v[i];
            if(po==l)
                l++;
            LDS[i]=l;
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,min(LIS[i],LDS[n-i-1])*2-1);
        printf("%d\n",ans);
    }

}
