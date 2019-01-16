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
vector<int>v;
int n,m,ar[35];
int gcd[105][105];
void print(int po, int sum,int nm)
{
    if(sum==0 && nm==m)
    {
        for(int i=0; i<nm-1; i++)
            printf("%d ",ar[i]);
        printf("%d\n",ar[nm-1]);
    }

    if(nm>=m||sum<=0)
        return;


    for(int i=po; i<=sum; i++)
    {
        int f=0;
        for(int j=0; j<nm; j++)
        {
            if(gcd[i][ar[j]]!=1)
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            ar[nm]=i;
            print(i,sum-i,nm+1);
            //v.pop_back();
        }

    }
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    for(int j=1; j<=100; j++)
    {
        for(int k=1; k<=100; k++)
        {
            gcd[j][k]=__gcd(j,k);
        }
    }
    int te;
    scanf("%d",&te);
    for(int i=0; i<te; i++)
    {

        scanf("%d %d",&n,&m);

        printf("Case %d:\n",i+1);
        print(1,n,0);
    }


}
