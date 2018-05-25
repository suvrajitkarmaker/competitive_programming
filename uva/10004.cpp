#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
#define Unique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x) to_string(x)
int a,b,t,n,color[250],x;
int red=1,blue=2,white=-1;
vector<int>v[250];
int bfs(int so)
{
    queue<int>q;
    q.push(so);
    color[so]=red;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(int i=0; i<v[x].size(); i++)
        {
            if(color[v[x][i]]==white)
            {
                if(color[x]==red)
                    color[v[x][i]]=blue;
                else
                    color[v[x][i]]=red;
                q.push(v[x][i]);
            }
            if(color[x]==color[v[x][i]])
                return 0;
        }
    }
    return 1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(scanf("%d",&n))
    {
        if(n==0)
        break;
        scanf("%d",&t);
        for(int i=0; i<t; i++)
        {
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        memset(color,-1,sizeof(color));
        if(bfs(0)==1)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
        for(int i=0; i<n; i++)
        {
            v[i].clear();
        }
    }
}
