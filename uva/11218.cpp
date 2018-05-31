#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
#define Unique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x) to_string(x)
#define stringtoint(x) stoll(x)
#define valid(nx,ny,row,col) nx>=0 && nx<row && ny>=0 && ny<col
#define MAX
struct st
{
    int x,y,z,s;
} a[83];
int n,k=3;
int num[83],ch[12],mu,mx=-1;
void rec(int t, int last)
{
    if(t==k+1)
    {
        memset(ch,0,sizeof(ch));
        mu=0;
        for(int i=1; i<=k; i++)
        {
            ch[a[num[i]].x]=1;
            ch[a[num[i]].y]=1;
            ch[a[num[i]].z]=1;
            mu+=a[num[i]].s;
        }
        int co=0;
        for(int i=1; i<=9; i++)
        {
            if(ch[i]==1)
                co++;
        }
        if(co==9)
        {
            if(mu>mx)
                mx=mu;
        }
        return;
    }
    for(int i=last+1; i<=n-k+t; i++)
    {
        num[t]=i;
        rec(t+1,i);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int i=1;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
            mx=-1;
        memset(num,0,sizeof(num));
        for(int i=1; i<=n; i++)
        {
            scanf("%d %d %d %d",&a[i].x,&a[i].y,&a[i].z,&a[i].s);

        }
        rec(1,0);
        printf("Case %d: %d\n",i++,mx);
    }
}
