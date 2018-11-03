#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;

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
#define max3(x,y,z)             max(z,max(x,y));
#define min3(x,y,z)             min(z,min(x,y));
#define MAX 100100000
#define eps 1e-15
vector<int>v[110];
int n,m,s,de,mv,x,y;
int dp[110][210];
int dfs(int so,int mov)
{
    if(mov==mv)
    {
        if(so==de)
            return 1;
        return 0;
    }
    int &ans=dp[so][mov];
    if(ans!=-1)
        return ans;
    ans=0;
    for(int i=0; i<v[so].size(); i++)
    {
        ans =ans | dfs(v[so][i],mov+1);
    }
    return ans;
}
int main()
{

    while(scanf("%d %d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        for(int i=1;i<=n;i++)
            v[i].clear();
        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        scanf("%d %d %d",&s,&de,&mv);
        CLR(dp,-1);
        if(dfs(s,0)==1)
            printf("Yes, Teobaldo can travel.\n");
        else
            printf("No, Teobaldo can not travel.\n");
    }
}
