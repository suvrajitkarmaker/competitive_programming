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
vector<int>v;

vector< vector<int> >vv;
void pnt(int num,int m)
{
    //printf("%d ",m);

    int ct=0;
    for(int i=m; i*i<=num; i++)
    {
        if(num%i==0)
        {
            v.push_back(i);
            pnt(num/i,i);
            v.pop_back();
        }
    }
    v.push_back(num);
    vv.push_back(v);
    v.pop_back();
    return;
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int n;
    while(scanf("%d",&n) && n)
    {
        v.clear();
        vv.clear();
        for(int i=2; i*i<=n; i++)
        {
            if(n%i==0)
            {
                v.push_back(i);
                pnt(n/i,i);
                v.pop_back();
            }
        }
        cout<<vv.size()<<endl;
        for(int i=0; i<vv.size(); i++)
        {
            for(int j=0; j<vv[i].size(); j++)
            {
                if(j==vv[i].size()-1)
                    printf("%d\n",vv[i][j]);
                else
                    printf("%d ",vv[i][j]);
            }
        }

    }


}
