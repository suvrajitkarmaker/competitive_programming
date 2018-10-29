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
#define MAX 100100000
#define eps 1e-15
int a[1000],b[1000],n,m;
int dp[110][110];
int lcs(int i,int j)
{
    if(i==n||j==m)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    int ans=0;
    if(a[i]==b[j])
        ans=1+lcs(i+1,j+1);
    else
    {
        int p1=lcs(i+1,j);
        int p2=lcs(i,j+1);
        ans=max(p1,p2);
    }
    dp[i][j]=ans;
    return dp[i][j];

}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int ct=1;
    while(scanf("%d %d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
            scanf("%d",&b[i]);
        CLR(dp,-1);
        printf("Twin Towers #%d\n",ct++);
        printf("Number of Tiles : %d\n\n",lcs(0,0));

    }

}
