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
#define MAX 10010
#define eps 1e-15
#define mod 1000000009
#define PII pair<int, int>
priority_queue<PII, vector<PII>, greater<PII> > q;
long double ncr(int n,int r)
{
    long double re=1.0;
    for(int i=1; i<=r; i++)
        re=re*(n-i+1)/i;

    return re;
}

int main()
{
      //READ("input.txt");
    // WRITE("output.txt");
    int a,b,x,y;
    while(scanf("%d %d %d %d",&x,&y,&a,&b)!=EOF)
    {
        long double p=ncr(x,y);
        long double q=ncr(a,b);
        printf("%0.5llf\n",p/q);
    }


}
