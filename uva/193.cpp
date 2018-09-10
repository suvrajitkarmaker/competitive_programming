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
#define MAX 105
#define eps 1e-9
vector<int>v[110],re;
int node,m,mx=0;
int color[110];
void BT(int no,int ct)
{

    //cout<<"dsaf"<<endl;
    if(no>node)
    {
        if(ct>mx)
        {
            mx=ct;
            re.clear();
            for(int i=1;i<=node;i++)
            {
                if(color[i]==1)
                    re.push_back(i);
            }
        }
        return;
    }

    int f=1;
    for(int i=0;i<v[no].size();i++)
    {
        if(color[v[no][i]]==1)
        {
            f=0;
            break;
        }
    }
    if(f==1)
    {
        color[no]=1;
        BT(no+1,ct+1);
        color[no]=0;
    }
    BT(no+1,ct);
}
int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te,x,y;
    cin>>te;
    for(int i=0;i<te;i++)
    {
        scanf("%d %d",&node,&m);
        for(int j=1;j<=node;j++)
            v[j].clear();
        for(int j=0;j<m;j++)
        {
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        mx=0;
        BT(1,0);
        printf("%d\n",mx);
        for(int j=0;j<re.size()-1;j++)
            printf("%d ",re[j]);
        printf("%d\n",re[re.size()-1]);

    }


}
