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
int n,m;
int dp[35],stor[35];
vector<int>v[35];
bool fn(vector<int>a,vector<int>b)
{
    for(int i=0; i<m; i++)
        if(a[i]<=b[i])
            return 0;
    return 1;
}

int DP(int po)
{
    if(dp[po]!=-1)
        return dp[po];
    int p2=1;
    for(int i=0; i<n; i++)
    {
        if(fn(v[i],v[po]))
        {
            int tm=p2;
            p2=max(p2,1+DP(i));
            if(p2>tm)
                stor[po]=i;

        }
    }
    return dp[po]=p2;


}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int x;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            v[i].clear();
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%d",&x);
                v[i].push_back(x);

            }
            sort(all(v[i]));
        }
        CLR(dp, -1);
        CLR(stor,-1);
        int res=-1,str;
        for(int i=0; i<n; i++)
        {
            int tm=DP(i);
            if(tm>res)
            {
                res=tm;
                str=i;
            }
        }
         printf("%d\n",res);
        while(stor[str]!=-1)
        {
            printf("%d ",str+1);
            str=stor[str];
        }
        printf("%d\n",str+1);
    }

}
