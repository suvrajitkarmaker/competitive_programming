#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define gcd3(x,y,z)                __gcd(__gcd(x,y),z)
#define INF                     INT_MAX
#define inf                     LONG_MAX
#define PI                      (2.0*acos(0.0))
#define Log(b,x)                (log(x)/log(b))
#define all(x)                  (x).begin(), (x).end()
#define Unique(x)               sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x)          to_string(x)
#define stringtoint(x)          stoll(x)
#define valid(nx,ny,row,col)    nx>0 && nx<=row && ny>0 && ny<=col
#define CLR(x,y)                memset(x,y,sizeof(x));
#define MAX 105
#define eps 1e-9
vector<int>gp[1010];
int v,e;
int dis[1010];
int bfs(int so)
{
    queue<int>q;
    q.push(so);
    for(int i=1;i<=v;i++)
        dis[i]=INF;
    int x;
    dis[so]=0;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(int i=0; i<gp[x].size(); i++)
        {
            if(dis[gp[x][i]]==INF)
            {
                dis[gp[x][i]]=dis[x]+1;
                q.push(gp[x][i]);
            }
        }
    }
    int mx=0;
    for(int i=1; i<=v; i++)
        mx=max(mx,dis[i]);

    return mx;


}
int main()
{

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while(scanf("%d",&v) && v)
    {
        char s[100],p[100];
        map<string,int>mp;
        for(int i=0; i<v; i++)
        {
            scanf("%s",s);
            mp[s]=i+1;
            gp[i+1].clear();
        }
        scanf("%d",&e);
        for(int i=0; i<e; i++)
        {
            scanf("%s %s",s,p);
            gp[mp[s]].push_back(mp[p]);
            gp[mp[p]].push_back(mp[s]);
        }
        int mx=0;
        for(int i=1; i<=v; i++)
        {
            mx=max(mx,bfs(i));
        }
        if(mx==INF)
            printf("-1\n");
        else
            printf("%d\n",mx);
    }

}
