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
int main()
{
    int n,m,q,r,c,te;
    scanf("%d",&te);
    while(te--)
    {
        scanf("%d %d %d",&n,&m,&q);
        string ar[n];
        for(int i=0; i<n; i++)
            cin>>ar[i];
        printf("%d %d %d\n",n,m,q);
        while(q--)
        {
            scanf("%d %d",&r,&c);
            int mi=0,res,fg=0;
            mi=min(r,n-r);
            mi=min(mi,min(c,m-c));
            //cout<<mi<<endl;
            for(int i=0; i<=mi; i++)
            {
                // fr=r-i;
                // fy=c-i;
                for(int j=r-i; j<=r+i; j++)
                {
                    for(int k=c-i; k<=c+i; k++)
                    {
                        if(ar[r][c]!=ar[j][k])
                        {
                            fg=1;
                            break;
                        }
                    }
                    if(fg==1)
                        break;
                }
                if(fg==1)
                    break;
                res=i;
            }
           // cout<<res*2+1<<endl;
           printf("%d\n",res*2+1);
        }
    }
}
