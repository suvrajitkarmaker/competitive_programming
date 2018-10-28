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
string s1,s2;
int dp[1010][1010],l1,l2;
int lcs(int i,int j)
{
    if(i==l1||j==l2)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans=0;
    if(s1[i]==s2[j])
        ans=1+lcs(i+1,j+1);
    else
    {
        int p1=lcs(i,j+1);
        int p2=lcs(i+1,j);
        ans=max(p1,p2);
    }
    dp[i][j]=ans;
    return dp[i][j];
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    while(getline(cin,s1))
    {
    //scanf("%s",s1);
    getline(cin,s2);
    l1=s1.size();
    l2=s2.size();
    CLR(dp,-1);
    printf("%d\n",lcs(0,0));
    }

}
