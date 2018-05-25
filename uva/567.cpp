#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
#define Unique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
int a[25][25],dst[25];
void bfs(int so)
{
    queue<int>q;
    q.push(so);
    dst[so]=0;
    int x;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(int i=1; i<=20; i++)
        {

            if(dst[i]==-1 && a[x][i]==1)
            {
                dst[i]=dst[x]+1;
                q.push(i);
            }

        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,x,s,d,te=1;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&x);
            a[1][x]=1;
            a[x][1]=1;
        }
        for(int j=2; j<=19; j++)
        {
            scanf("%d",&n);
            for(int i=1; i<=n; i++)
            {
                scanf("%d",&x);
                a[j][x]=1;
                a[x][j]=1;
            }
        }
        /*for(int j=1; j<=19; j++)
        {
            cout<<j<<endl;
            for(int i=1; i<=20; i++)
            {
                if(a[j][i]==1)
                cout<<i<<" ";
            }
            cout<<endl;
        }*/
        int qr;
        scanf("%d",&qr);
        printf("Test Set #%d\n",te++);
        for(int i=0; i<qr; i++)
        {
            scanf("%d %d",&s,&d);
            memset(dst,-1,sizeof(dst));
            bfs(s);
            if(s>=1 && s<=9)
                printf(" %d",s);
            else
                printf("%d",s);
            printf(" to ");
            if(d>=1 && d<=9)
                printf(" %d: %d\n",d,dst[d]);
            else
                printf("%d: %d\n",d,dst[d]);
        }
        printf("\n");
    }
}
