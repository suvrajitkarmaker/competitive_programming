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
#define valid(nx,ny,row,col)    nx>=0 && nx<row && ny>=0 && ny<col
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
#define eps 1e-8
int n,a[1010],b[1010];

int dp[1010][6005];
int call(int po,int pre)
{

    if(po==n)
        return 0;
    if(pre<=0)
        return 0;
    if(dp[po][pre]!=-1)
        return dp[po][pre];
    int p1=0,p2=0;

    p1=call(po+1,pre);
    if(a[po]<=pre)
    {
        p2=1+call(po+1,min(b[po],pre-a[po]));
    }
    dp[po][pre]=max(p1,p2);

    return dp[po][pre];
}
int main()
{
     //READ("input.txt");
 //WRITE("output.txt");
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&a[i],&b[i]);
        }
        CLR(dp,-1);
        cout<<call(0,6000)<<endl;
    }


}
