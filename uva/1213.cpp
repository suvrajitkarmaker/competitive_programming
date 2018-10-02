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
bool s[1250];
int a[1200],l=0;
void siv()
{
    int n=1120;
    for(int i=4; i<=n; i+=2)
    {
        s[i]=1;
    }
    for(int i=3; i*i<=n; i+=2)
    {
        if(s[i]==0)
        {
            for(int j=i*i; j<=n; j+=i)
                s[j]=1;
        }
    }
    s[1]=1;
    for(int i=2; i<=n; i++)
    {
        if(s[i]==0)
        {
            a[l++]=i;
        }
    }
}

int n,k;
ll dp[1122][15][190];
int DP(int po,int nm,int vl)
{
    if(nm==0 && vl==0)
    return 1;
    if(nm==0 || vl==0)
        return 0;
    if(po>=l)
        return 0;
    if(dp[vl][nm][po]!=-1)
        return dp[vl][nm][po];

    int p1=0,p2=0;
    p1=DP(po+1,nm,vl);

    if(vl-a[po]>=0)
    p2=DP(po+1,nm-1,vl-a[po]);

    dp[vl][nm][po]=p1+p2;
    return dp[vl][nm][po];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    siv();
    CLR(dp,-1);
    while(scanf("%d %d",&n,&k))
    {
        if(n==0 && k==0)
            break;
        printf("%lld\n",DP(0,k,n));
    }

}
