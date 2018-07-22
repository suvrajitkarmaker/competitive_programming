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
ll ar[510],m,k,res[510],lo,hi;
ll fn(ll x)
{
    ll ct=1,sum=0;
    for(int i=m-1; i>=0; i--)
    {
        if(ar[i]>x)
            return k+1;
        sum+=ar[i];
        if(sum>x)
        {
            ct++;
            sum=ar[i];
        }
    }
    return ct;
}
ll BS()
{
    ll mid,mi;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        //cout<<mid<<endl;
        if(fn(mid)<=k)
        {
            mi=mid;
            hi=mid-1;

        }
        else
            lo=mid+1;
    }
    return mi;
}
int main()
{
   //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te;
    cin>>te;
    while(te--)
    {
        scanf("%lld %lld",&m,&k);
        hi=0,lo=0;
        for(int i=0; i<m; i++)
        {
            scanf("%lld",&ar[i]);
            lo=min(lo,ar[i]);
            hi+=ar[i];
        }
        ll lim=BS();
        //cout<<lim<<endl;
        CLR(res,0);
        ll ct=1,sum=0;
        for(int i=m-1; i>=0; i--)
        {
            sum+=ar[i];
            if(sum>lim && i<m-1)
            {
                ct++;
                res[i]=1;
                sum=ar[i];
            }
        }
        //cout<<ct<<endl;
        for(int i=0; i<m && ct<k; i++)
        {

            if(!res[i])
            {
                res[i]=1;
                ct++;
            }
        }
        for(int i=0; i<m; i++)
        {
            if(i==0)
                printf("%lld",ar[i]);
            else
                printf(" %lld",ar[i]);
            if(res[i]==1)
                printf(" /");
        }
        cout<<endl;
    }

}
