#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF                     LLONG_MAX
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
int ar[MAX],fin[MAX],n,q;
int tree[MAX*3];
void setTree(int node,int l, int h)
{
    if(l==h)
    {
        tree[node]=ar[l];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(l+h)/2;
    setTree(left,l,mid);
    setTree(right,mid+1,h);
    tree[node]=max(tree[left],tree[right]);
}
int quary(int node, int l, int h,int x,int y)
{
    if(y<l||x>h)
        return -1;
    if(l>=x && h<=y)
        return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(l+h)/2;
    int x1=quary(left,l,mid,x,y);
    int x2=quary(right,mid+1,h,x,y);
    return max(x1,x2);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        scanf("%d",&q);
        memset(ar,0,sizeof(ar));
        memset(fin,0,sizeof(fin));
        int a[n];
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        int ct,ti;
        for(int i=0; i<n; i++)
        {
            ct=1;
            ti=i;
            fin[i]=ti;
            while((i+1)<n && a[i]==a[i+1])
            {
                fin[i]=ti;
                ct++;
                i++;

            }
            fin[i]=ti;
            for(int j=ti; j<=i; j++)
                ar[j]=ct;
        }
        setTree(1,0,n-1);
        int lb,rb,x,y,mx;
        for(int i=0; i<q; i++)
        {
            scanf("%d %d",&x,&y);
            x--;
            y--;
            if(fin[x]==fin[y])
            {
                printf("%d\n",y-x+1);
                continue;
            }
            lb=x-fin[x];
            lb=ar[x]-lb;
            rb=ar[y]-(y-fin[y]+1);
            rb=ar[y]-rb;
            mx=max(lb,rb);
            x+=lb;
            y-=rb;
            //cout<<x<<" "<<mx<<endl;
            printf("%d\n",max(mx,quary(1,0,n-1,x,y)));
        }
    }
}
