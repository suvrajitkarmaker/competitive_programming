#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int fx[]= {1,-1,-2,2,-2,2,-1,1};
int fy[]= {2,2,1,1,-1,-1,-2,-2};
#define all(x) (x).begin(), (x).end()
#define Unique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x) to_string(x)
#define valid(nx,ny,row,col) nx>=0 && nx<row && ny>=0 && ny<col
int ro=8,co=8,dis[10][10];
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
        for(int i=0; i<8; i++)
        {
            tx=x+fx[i];
            ty=y+fy[i];
            if(valid(tx,ty,ro,co)==1 && dis[tx][ty]==-1)
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
    string a,b;
    string al;
    while(getline(cin,al) && al.size())
    {
        stringstream ss(al);
        ss>>a>>b;
        memset(dis,-1,sizeof(dis));
        bfs(a[0]-97,a[1]-48-1);
        cout<<"To get from "<<a<<" to "<<b<<" takes "<<dis[b[0]-97][b[1]-48-1]<<" knight moves."<<endl;
    }
}
