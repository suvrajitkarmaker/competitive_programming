#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
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
#define MAX 100100000
#define eps 1e-15
int v[510][10];
int n;
int dp[510][105],track[510][105];
int ind(int j)
{
    if(j%2==0)
        return j+1;
    return j-1;
}
int DP(int po,int clpos)
{
    if(po<0)
        return 0;
    //if(dp[po][clpos]!=-1)
        int &ans=dp[po][clpos];
        if(ans!=-1)
            return ans;
        ans=0;
    int p1=0,p2=0,tm;
    for(int j=0; j<6; j++)
    {
        if(clpos==0||v[po][j]==clpos)
        {
            tm=p1;
            p1=max(p1,1+DP(po-1,v[po][ind(j)]));
            if(p1>tm)
            {
                track[po][clpos]=ind(j);
            }
            ans=p1;

        }
    }
    p2=DP(po-1,clpos);
    if(p2>ans)
    {
        track[po][clpos]=-1;
        ans=p2;
    }
    return ans;
}
void print(int po, int cl)
{
    if(po<0)
        return;
    int xx=track[po][cl];
    if(xx!=-1)
    {
        print(po-1,v[po][xx]);
        int tm=xx;
        printf("%d ",po+1);
        if(tm==0)
            printf("front\n");
        else if(tm==1)
            printf("back\n");
        else if(tm==2)
            printf("left\n");
        else if(tm==3)
            printf("right\n");
        else if(tm==4)
            printf("top\n");
        else if(tm==5)
            printf("bottom\n");
    }
    else
        print(po-1,cl);
}
int main()
{
    int x,ct=1;
    while(scanf("%d",&n) && n>0)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<6; j++)
            {
                scanf("%d",&v[i][j]);
            }
        }
        CLR(dp,-1);
        CLR(track,-1);
        if(ct>1)
            printf("\n");
        printf("Case #%d\n",ct++);
        printf("%d\n",DP(n-1,0));
        print(n-1,0);
    }
}
