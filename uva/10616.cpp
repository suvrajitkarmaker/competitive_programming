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
int a[205],n,d,m;
int dp[205][15][45];
int cal(int po,int ct,int rem)
{

    if(ct==m)
        return rem==0;

    if(po>=n||ct>m)
        return 0;


    if(dp[po][ct][rem]!=-1)
        return dp[po][ct][rem];


    int p1=0,p2=0;
    p1=cal(po+1,ct,rem);
    p2=cal(po+1,ct+1,(rem+a[po])%d);
    dp[po][ct][rem]=p1+p2;

    return dp[po][ct][rem];
}
int main()
{
    //READ("input.txt");
   //  WRITE("output.txt");
    int q,ct=1;
    while(scanf("%d %d",&n,&q) && n && q)
    {
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);


        printf("SET %d:\n",ct++);

        for(int i=1; i<=q; i++)
        {
            CLR(dp,-1);
            scanf("%d %d",&d,&m);
            printf("QUERY %d: %d\n",i,cal(0,0,0));
        }
    }


}
