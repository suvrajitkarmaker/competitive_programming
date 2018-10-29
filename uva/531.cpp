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
vector<string>v1,v2;
int dp[110][110],n,m;
int lcs(int i,int j)
{
    if(i==v1.size()||j==v2.size())
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    int ans=0;
    if(v1[i]==v2[j])
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
string str;
void printlcs(int i,int j)
{
    if(i==v1.size()||j==v2.size())
    {
        str.erase(str.end()-1);
        cout<<str<<endl;
        return;
    }
    if(v1[i]==v2[j])
    {
        str+=v1[i];
        str+=" ";
        printlcs(i+1,j+1);
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1])
            printlcs(i+1,j);
        else
            printlcs(i,j+1);
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    char s[10000];
    while(scanf("%s",s)!=EOF)
    {
        v1.clear();
        v2.clear();
         v1.push_back(s);
        while(scanf("%s",s))
        {
            if(s[0]=='#')
                break;
            v1.push_back(s);
        }
        while(scanf("%s",s))
        {
            if(s[0]=='#')
                break;
            v2.push_back(s);
        }
        CLR(dp,-1);
        str.clear();
        lcs(0,0);
        printlcs(0,0);
    }

}
