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
struct node
{
    int a,b;
} inp[100];
int x,y,q,mark[20],res=INT_MAX;
void BT(int po,int cost,int le)
{
    if(le==q)
    {
        cost+=abs(inp[0].a-inp[po].a)+abs(inp[0].b-inp[po].b);
        res=min(res,cost);
        return;
    }

    for(int i=1; i<=q; i++)
    {

        if(mark[i]==0)
        {
            mark[i]=1;
            BT(i,cost+abs(inp[i].a-inp[po].a)+abs(inp[i].b-inp[po].b),le+1);
            mark[i]=0;
        }
    }
}
int main()
{
    int te;
    cin>>te;
    while(te--)
    {
        scanf("%d %d %d %d %d",&x,&y,&inp[0].a,&inp[0].b,&q);
        for(int i=1; i<=q; i++)
        {
            scanf("%d%d",&inp[i].a,&inp[i].b);
        }
        res=INT_MAX;
        BT(0,0,0);
        printf("The shortest path has length %d\n",res);
    }
}
