#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF                     INT_MAX
#define inf                     LONG_MAX
#define PI                      (2.0*acos(0.0))
#define Log(b,x)                (log(x)/log(b))
#define all(x)                  (x).begin(), (x).end()
#define Unique(x)               sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x)          to_string(x)
#define stringtoint(x)          stoll(x)
#define valid(nx,ny,row,col)    nx>=0 && nx<row && ny>=0 && ny<col
#define CLR(x,y)                memset(x,y,sizeof(x));
#define MAX 100100
vector<int>vl[20010],gp[20010];
int mark[20010],dis[20010],n;
int dj(int so,int de)
{
    set<pair<int,int> >st;
    pair<int,int>pr;
    st.insert({0,so});
    for(int i=0; i<n; i++)
        dis[i]=INF;
    dis[so]=0;
    while(!st.empty())
    {
        pr=*st.begin();
        st.erase(pr);
        int ds=pr.first;
        int node=pr.second;
        for(int i=0; i<gp[node].size(); i++)
        {
            int u=gp[node][i];
            if(dis[node]+vl[node][i]<dis[u])
            {
                dis[u]=dis[node]+vl[node][i];
                st.insert({dis[u],u});
            }
        }
    }
    if(dis[de]==INF)
        return -1;
    return dis[de];

}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te,m,s,de,x,y,z;
    scanf("%d",&te);
    for(int i=1; i<=te; i++)
    {
        scanf("%d %d %d %d",&n,&m,&s,&de);
        for(int j=0; j<n; j++)
        {
            gp[j].clear();
            vl[j].clear();
        }

        for(int j=0; j<m; j++)
        {
            scanf("%d %d %d",&x,&y,&z);
            gp[x].push_back(y);
            gp[y].push_back(x);
            vl[x].push_back(z);
            vl[y].push_back(z);
        }
        CLR(mark,0);
        int dd=dj(s,de);
        if(dd==-1)
            printf("Case #%d: unreachable\n",i);
        else
            printf("Case #%d: %d\n",i,dd);

    }
}
