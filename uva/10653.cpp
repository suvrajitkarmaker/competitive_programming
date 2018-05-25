#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
#define all(x) (x).begin(), (x).end()
#define Unique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x) to_string(x)
#define valid(nx,ny,row,col) nx>=0 && nx<row && ny>=0 && ny<col
int grp[1010][1010],ro,co,dis[1010][1010];
int bfs(int sx, int sy)
{
    queue< pair<int,int> >q;
    q.push(make_pair(sx,sy));
    dis[sx][sy]=0;
    int x,y,tx,ty;
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            tx=x+fx[i];
            ty=y+fy[i];
            if(valid(tx,ty,ro,co)==1 && dis[tx][ty]==-1 && grp[tx][ty]==0)
            {
                dis[tx][ty]=dis[x][y]+1;
                q.push(make_pair(tx,ty));
            }
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(scanf("%d %d",&ro,&co))
    {
        if(ro==0 && co==0)
            break;
        int t,a,b,c,sx,sy,dx,dy;
        scanf("%d",&t);
        memset(grp,0,sizeof(grp));
        memset(dis,-1,sizeof(dis));
        for(int i=0; i<t; i++)
        {
            scanf("%d %d",&a,&b);
            for(int j=0; j<b; j++)
            {
                scanf("%d",&c);
                grp[a][c]=-1;
            }
        }
        scanf("%d %d",&sx,&sy);
        scanf("%d %d",&dx,&dy);
        bfs(sx,sy);
        cout<<dis[dx][dy]<<endl;
    }
}
