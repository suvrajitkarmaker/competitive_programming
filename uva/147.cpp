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
#define MAX 105
#define eps 1e-9
double ar[]= {10000,5000,2000,1000,500,200,100,50,20,10,5};
ll dp[20][30010];

ll DP(int po,int vl)
{
    //cout<<vl<<endl;
    if(vl==0)
            return 1;
    if(vl<0)
        return 0;
    if(po>=11)
    {
        return 0;
    }
    if(dp[po][vl]!=-1)
        return dp[po][vl];
    ll p1=0,p2=0;
    p1=DP(po+1,vl);
    if(vl-ar[po]>=0)
    {
        p2=DP(po,vl-ar[po]);
    }
    dp[po][vl]=p1+p2;

    return dp[po][vl];
}
ll fn(ll n)
{
    if(n==0)
        return 1;
    ll ct=0;
    while(n)
    {
        n/=10;
        ct++;
    }
    return ct;
}
int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    CLR(dp,-1);
    string s;
    while(cin>>s)
    {
        if(s=="0.00")
            break;
        int inp=0,input=0;
        //inp/=10;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='.')
                continue;
            inp=(inp*10)+s[i]-48;
        }
         for(int i=0;s[i]!='.';i++)
        {
            input=(input*10)+s[i]-48;
        }
        //cout<<inp<<endl;
        ll res=DP(0,inp);
        for(int i=1; i<=3-fn(input); i++)
            printf(" ");
        cout<<s;
        for(int i=1; i<=17-fn(res); i++)
            printf(" ");
        printf("%lld\n",res);

    }


}
