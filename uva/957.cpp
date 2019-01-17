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

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int s,n;
    while(scanf("%d %d",&s,&n)!=EOF)
    {
        int a[n];
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);

        int mx=-1,dd,x,y;

        for(int i=0; i<n; i++)
        {
            int po=upper_bound(a,a+n,(a[i]+s)-1)-a;
            if(po>=n)
                po--;
            else if(a[po]>(a[i]+s)-1)
                po--;
            dd=(po-i)+1;
            if(dd>mx)
            {
                x=a[i];
                y=a[po];
                mx=dd;
            }
        }
        printf("%d %d %d\n",mx,x,y);
    }

}

