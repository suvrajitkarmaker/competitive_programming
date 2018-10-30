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
int dp[1010][1010];
string s;
int hobe(int i,int j)
{
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    int ans=0;

    if(s[i]==s[j])
    {
        ans=hobe(i+1,j-1);
    }
    else
    {
        int a=hobe(i+1,j);
        int b=hobe(i,j-1);
        int c=hobe(i+1,j-1);
        ans=1+min3(a,b,c);
    }
    dp[i][j]=ans;
    return dp[i][j];
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int te;
    scanf("%d",&te);
    for(int i=1; i<=te; i++)
    {
        cin>>s;
        CLR(dp,-1);
        printf("Case %d: %d\n",i,hobe(0,s.size()-1));
    }
}
