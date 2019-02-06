
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
#define mod 1000000007
ll md;
struct mt
{
    ll ar[5][5];

};

mt matrixmulti(mt a,mt b)
{
    struct mt x;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            x.ar[i][j]=0;
            for(int k=0; k<2; k++)
            {
                x.ar[i][j]+=(a.ar[i][k]*b.ar[k][j])%md;
                x.ar[i][j]%=md;
            }
        }
    }
    return x;
}
ll bg (mt a, ll p)
{
    if(p==-1)
        return 0;
    struct mt res;
    res.ar[0][0]=1;
    res.ar[0][1]=0;
    res.ar[1][0]=0;
    res.ar[1][1]=1;
    struct mt x = a;

    while(p>0)
    {
        if (p & 1)
        {
            res = matrixmulti(res,x);
        }
        x =matrixmulti(x,x);
        p = p >> 1;
    }

    return res.ar[0][0]%mod;
}
int main()
{
    // READ("input.txt");
    //  WRITE("output.txt");
    struct mt a,r;
    a.ar[0][0]=1;
    a.ar[0][1]=1;
    a.ar[1][0]=1;
    a.ar[1][1]=0;
    r=a;
    ll n,m,te;
    ll x,y;
    while(scanf("%lld %lld",&n,&m)!=EOF)
    {

        md=1;
        for(int i=0;i<m;i++)
        md*=2;
        if(n==0)
            printf("0\n");
        else if(n==1)
            printf("1\n");
        else
        {

            printf("%lld\n",bg(a,n-1));
        }

    }
}
