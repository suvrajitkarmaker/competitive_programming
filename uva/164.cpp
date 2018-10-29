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
#define max3(x,y,z)             max(z,max(x,y));
#define min3(x,y,z)             min(z,min(x,y));
#define MAX 100100000
#define eps 1e-15
int dp[50][50];
string x,y;
int editdistance(int i,int j)
{
    if(i==x.size())
        return y.size()-j;

    if(j==y.size())
        return x.size()-i;

    if(dp[i][j]!=-1)
        return dp[i][j];
    int ans=0;
    if(x[i]==y[j])
        ans=editdistance(i+1,j+1);
    else
    {
        int a=1+editdistance(i+1,j+1);
        int b=1+editdistance(i+1,j);
        int c=1+editdistance(i,j+1);
        ans=min3(a,b,c);
    }
    dp[i][j]=ans;
    return dp[i][j];
}
void printpath(int i,int j)
{

    if(i==x.size())
    {
        for(int k=j; k<y.size(); k++)
        {
            printf("I%c%02d",y[k],k+1);
        }
        return;
    }
    if(j==y.size())
    {
        for(int k=i; k<x.size(); k++)
        {
            printf("D%c%02d",x[k],j+1);
        }
        return;
    }
    if(x[i]==y[j])
        printpath(i+1,j+1);

    else
    {
        int mi=dp[i][j];
        if(mi==(editdistance(i+1,j+1)+1))
        {
            printf("C%c%02d",y[j],j+1);
            printpath(i+1,j+1);
        }
        else if(mi==(editdistance(i+1,j)+1))
        {
            printf("D%c%02d",x[i],j+1);
            printpath(i+1,j);
        }
        else
        {
            printf("I%c%02d",y[j],j+1);
            printpath(i,j+1);
        }
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    while(cin>>x)
    {
        if(x=="#")
            break;
        cin>>y;
        CLR(dp,-1);
        editdistance(0,0);
        printpath(0,0);
        printf("E\n");
    }
}
