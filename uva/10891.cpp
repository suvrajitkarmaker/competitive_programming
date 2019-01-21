#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
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
#define MP(x, y) make_pair(x, y)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define pii pair< int, int >
#define psi pair< string, int >
#define MAX 100100000
#define eps 1e-15
#define mod 100000007
int a[105];
int dp[105][105],track[105][105];
int call(int l,int r)
{
    if(l>r)
        return 0;

    if(track[l][r])
        return dp[l][r];
    track[l][r]=1;

    dp[l][r]=-99999999;
    for(int i=l,sum=0; i<=r; i++)
    {
        sum+=a[i];

        dp[l][r]=max(dp[l][r],sum-call(i+1,r));
    }
    for(int i=r,sum=0; i>=l; i--)
    {
        sum+=a[i];

        dp[l][r]=max(dp[l][r],sum-call(l,i-1));
    }
    return dp[l][r];
}
int main()
{
    //READ("input.txt");
    // WRITE("output.txt");
    int n;
    while(scanf("%d",&n) && n)
    {
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        CLR(track,0);
        printf("%d\n",call(0,n-1));

    }

}
