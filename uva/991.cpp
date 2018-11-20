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
int cat(int n,int m)
{
    return (((2*n+2)*(2*n+1))*m)/((n+2)*(n+1));
}
int main()
{
    int a[100];
    a[0]=1;
    a[1]=1;
   //cout<<cat(1,2)<<endl;
    for(int i=2;i<=10;i++)
    {
        a[i]=cat(i-1,a[i-1]);
      //  cout<<a[i]<<endl;
    }
    int n,ct=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(ct>0)
            printf("\n");
        printf("%d\n",a[n]);
        ct++;
    }

}
