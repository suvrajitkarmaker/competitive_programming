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
#define MAX 100100000
#define eps 1e-15
struct st
{
    char s[100];
    int x,y;
} a[20];
int n;
int visit[20];
double mi=99999999999.0;
double dis(st A,st B)
{
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y) * (A.y-B.y));
}
void DP(int po,double sum)
{
    if(po==n)
    {
        // cout<<sum<<endl;
        mi=min(mi,sum);
        return;
    }
    if(sum>mi)
        return;
//cout<<sum<<endl;
    int i;
    for(i=0; i<n*2; i++)
    {
        if(!visit[i])
        {
            visit[i]=1;
            break;
        }
    }
    for(int j=i+1; j<n*2; j++)
    {
        if(!visit[j])
        {
            visit[j]=1;
            DP(po+1, sum+dis(a[i],a[j]));
            visit[j]=0;
        }
    }
    visit[i]=0;

}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int ct=1;
    while(scanf("%d",&n) && n)
    {
        for(int i=0; i<n*2; i++)
        {
            scanf("%s %d %d",a[i].s,&a[i].x,&a[i].y);
        }
        mi=LONG_MAX;
        CLR(visit,0);
        DP(0,0.0);
        printf("Case %d: %0.2f\n",ct++,mi);
    }

}
