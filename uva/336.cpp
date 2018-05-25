#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
#define Unique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
vector<int>v[200010];
set<int>s;
int dis[100010];
void bfs(int so)
{
    queue<int>q;
    q.push(so);
    dis[so]=0;
    int x;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(int i=0; i<v[x].size(); i++)
        {
            if(dis[v[x][i]]==-1)
            {
                dis[v[x][i]]=dis[x]+1;
                q.push(v[x][i]);
            }
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,a,b,te=1;
    while(scanf("%d",&n) && n!=0)
    {
        s.clear();
        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
            s.insert(a);
            s.insert(b);
        }
        while(scanf("%d %d",&a,&b))
        {
            if(a==0 && b==0)
                break;
            memset(dis,-1,sizeof(dis));
            bfs(a);
            int co=0;
            for(auto i=s.begin(); i!=s.end(); i++)
            {
                if(dis[*i]>b||dis[*i]==-1)
                {
                    co++;
                }

            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",te++,co,a,b );
        }
        for(auto i=s.begin(); i!=s.end(); i++)
        {
            v[*i].clear();
        }
    }
}
