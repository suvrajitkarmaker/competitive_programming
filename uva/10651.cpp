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
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int dp[(1<<15)+2];
int hobe(int mask,int fg)
{
    if(fg==1)
    {
        int ct=0;
        for(int i=0; i<12; i++)
        {
            if(check(mask,i)==1)
                ct++;
        }
        return ct;
    }
    if(dp[mask]!=-1)
        return dp[mask];

    int ans=1<<28;
    for(int i=0; i<11; i++)
    {
        if(check(mask,i)==1 && check(mask,i+1)==1)
        {
            int xx=reset(mask,i+1);
            xx=reset(xx,i);
            if(i>0 && check(mask,i-1)==0 )
            {
                ans=min(ans,hobe(Set(xx,i-1),0));
            }
            if(i+2<12 && check(mask,i+2)==0 )
            {
                ans=min(ans, hobe(Set(xx,i+2),0) );
            }
        }
    }
    ans=min(ans,hobe(mask,1));
    dp[mask]=ans;
    return dp[mask];
}
int main()
{

//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
    char s[1000];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int x=0;
        for(int i=0; i<12; i++)
        {

            if(s[i]=='o')
                x=(x<<1)|1;
            else
                x=(x<<1)|0;
        }
        CLR(dp,-1);
        //cout<<x<<endl;
        cout<<hobe(x,0)<<endl;
    }
}
