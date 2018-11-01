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
vector<int>v;
int n,m,k,x,res;
int dp[1010][1010];
int di(int t)
{
    if(t==0)
        return 0;
    if(t<=10)
        return -k;
    return (t-10)*(t-10);
}
int hobe(int po,int sum)
{
    if(po>=n)
        return 1;
    int ans=INT_MAX;
    if(dp[po][sum]!=-1)
        return dp[po][sum];

    if(v[po]+sum<=m)
    {
        ans=1+hobe(po+1,0);
        ans=min(ans,hobe(po+1,sum+v[po]));
    }
    else
        ans=1+hobe(po+1,v[po]);
    return dp[po][sum]=ans;
    //return ans;

}
int divalue(int po,int nichi)
{

    if(po>=n)
    {
        if(nichi==res)
            return 0;
        else
            return 2e9;
    }
    if(nichi>=res)
        return 2e9;
    if(dp[po][nichi]!=-1)
        return dp[po][nichi];
    int ans=2e9,sum=0;
    for(int i=po; i<n; i++)
    {
        sum+=v[i];
        if(sum<=m)
        {
            ans=min(ans,di(m-sum)+divalue(i+1,nichi+1));
        }
        else
            break;
    }
    return dp[po][nichi]=ans;
}
int main()
{
////    freopen("input.txt", "r", stdin);
////    freopen("output.txt", "w", stdout);
    int te=1;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        scanf("%d %d",&m,&k);
        v.clear();
        for(int i=0; i<n; i++)
        {
            scanf("%d",&x);
            v.push_back(x);
        }
        CLR(dp,-1);
        res=hobe(0,0);
        //cout<<res<<endl;
        CLR(dp,-1);
        if(te>1)
            printf("\n");
        printf("Case %d:\n",te);
        te++;
        printf("Minimum number of lectures: %d\nTotal dissatisfaction index: %d\n",res,divalue(0,0));
    }

}
