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
#define valid(nx,ny,row,col)    nx>=0 && nx<row && ny>=0 && ny<col
#define CLR(x,y)                memset(x,y,sizeof(x));
#define MAX 100100000
#define eps 1e-15
int fx[]= {0,0,1,-1};
int fy[]= {1,-1,0,0};
int a[110][110],ch[110][110],r,c,le=-1,ans=-1;
void BT(int i,int j,int l)
{
    //cout<<i<<" "<<j<<endl;
    if(ch[i][j]!=0)
        return;
    le=max(le,l);
    for(int k=0; k<4; k++)
    {
        int xx=fx[k]+i;
        int yy=fy[k]+j;
        if(valid(xx,yy,r,c) && a[xx][yy]<a[i][j])
        {
            ch[i][j]=1;
            BT(xx,yy,l+1);
            ch[i][j]=0;
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    char s[1000];
    int tst;
    cin>>tst;
    while(tst--)
    {
        scanf("%s %d %d",s,&r,&c);
        memset(a,0,sizeof(a));
        ans=-1;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
                scanf("%d",&a[i][j]);
        }
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                le=-1;
                //cout<<"asd"<<endl;
                memset(ch,0,sizeof(ch));
                BT(i,j,1);
                ans=max(ans,le);
                //cout<<ans<<endl;
            }
        }
        printf("%s: %d\n",s,ans);
    }

}
