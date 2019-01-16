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
 //   READ("input.txt");
//WRITE("output.txt");
    int te;
    scanf("%d",&te);
    while(te--)
    {

        ll x1,x2,y1,y2,n,s;
        scanf("%lld %lld",&s,&n);
        ll ar[s][s],sum[s+10],mx=-9999999999999999;

        for(int j=0; j<s; j++)
        {
            for(int k=0; k<s; k++)
                ar[j][k]=1;
        }
        for(int i=0; i<n; i++)
        {
            scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);

            for(int j=x1-1; j<x2; j++)
            {
                for(int k=y1-1; k<y2; k++)
                    ar[j][k]=-99999999;
            }
        }

        /*for(int j=0; j<s; j++)
        {
            for(int k=0; k<s; k++)
                printf("%d ",ar[j][k]);
            printf("\n");
        }*/
        for(int i=0; i<s; i++)
        {
            memset(sum,0,sizeof(sum));
            for(int j=i; j<s; j++)
            {
                ll ss=0;
                for(int k=0; k<s; k++)
                {
                    sum[k]+=ar[j][k];
                    if(ss>=0)
                        ss+=sum[k];
                    else
                        ss=sum[k];
                    mx=max(ss,mx);
                }
            }
        }
        mx=max(mx,0LL);
        printf("%lld\n",mx);
    }

}
