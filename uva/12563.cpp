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
int n,a[100],m;

pair<int,int> dp[55][9100];
bool track[55][9100];
pair<int,int> call(int po,int ti)
{

    if(po==n)
        return {1,678};
    auto &p1=dp[po][ti];
    if(track[po][ti]==true)
        return p1;
    track[po][ti]=true;
    p1=call(po+1,ti);

    if(ti+a[po]<m)
    {
        auto p2=call(po+1,ti+a[po]);
        p2.first++;
        p2.second+=a[po];
        p1=max(p1,p2);
    }

    return p1;
}
int main()
{

    int te;
    cin>>te;
    for(int ii=1; ii<=te; ii++)
    {
        scanf("%d %d",&n,&m);

        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        CLR(track,0);
        //CLR(dp,{0,0});
        auto re=call(0,0);

        printf("Case %d: %d %d\n",ii,re.first,re.second);
    }

}
