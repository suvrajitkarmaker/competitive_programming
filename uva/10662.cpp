#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
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
#define max3(x,y,z)             max(z,max(x,y));
#define min3(x,y,z)             min(z,min(x,y));
#define MP(x, y) make_pair(x, y)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define pii pair< int, int >
#define psi pair< string, int >
#define MAX 100100000
#define eps 1e-8

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int t,r,h;
    while(scanf("%d %d %d",&t,&r,&h)!=EOF)
    {
        int fs[t][r+1],se[r][h+1],th[h][t+1];

        for(int i=0; i<t; i++)
        {
            for(int j=0; j<=r; j++)
                scanf("%d",&fs[i][j]);
        }
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<=h; j++)
                scanf("%d",&se[i][j]);
        }
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<=t; j++)
                scanf("%d",&th[i][j]);
        }
        int mn=INT_MAX,sum,rx,ry,rz;
        // cout<<h<<endl;
        for(int i=0; i<t; i++)
        {

            for(int j=1; j<=r; j++)
            {
                if(fs[i][j]==0)
                {
                    sum=fs[i][0];
                    for(int k=1; k<=h; k++)
                    {
                        //  cout<<k<<endl;

                        if(se[j-1][k]==0)
                        {
                            sum+=se[j-1][0];
                            //cout<<k<<" "<<i<<" "<<sum<<endl;

                            if(th[k-1][i+1]==0)
                            {

                                sum+=th[k-1][0];
                                //cout<<sum<<" "<<i<<endl;
                                //mn=min(mn,sum);
                                if(sum<mn)
                                {
                                    rx=i;
                                    ry=j-1;
                                    rz=k-1;
                                    mn=sum;
                                }
                                sum-=th[k-1][0];
                            }
                            sum-=se[j-1][0];
                            //cout<<"dab"<<endl;
                        }
                    }
                    //out<<"bal"<<endl;
                }
            }
        }
        if(mn==INT_MAX)
            printf("Don't get married!\n");
        else
            printf("%d %d %d:%d\n",rx,ry,rz,mn);
    }

}

