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
bool s[10000000];
long long int a[1000000];
int l=0;
void siv()
{
    int n=1300000;
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

int main()
{
    //READ("input.txt");
    //  WRITE("output.txt");
    siv();
    int n,x,y;
    while(scanf("%d",&n) && n)
    {
        if(s[n]==0)
        {
            printf("0\n");
            continue;
        }
        x=lower_bound(a,a+l,n)-a;
        x--;
        y=upper_bound(a,a+l,n)-a;
        printf("%lld\n",a[y]-a[x]);
    }

}
