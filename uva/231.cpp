#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define gcd3(x,y,z)                __gcd(__gcd(x,y),z)
#define INF                     INT_MAX
#define inf                     LONG_MAX
#define PI                      (2.0*acos(0.0))
#define Log(b,x)                (log(x)/log(b))
#define all(x)                  (x).begin(), (x).end()
#define Unique(x)               sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x)          to_string(x)
#define stringtoint(x)          stoll(x)
#define valid(nx,ny,row,col)    nx>0 && nx<=row && ny>0 && ny<=col
#define CLR(x,y)                memset(x,y,sizeof(x));
#define MAX 105
#define eps 1e-9
vector<int>v,p;
int main()
{

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int n,ct=1;
    while(scanf("%d",&n))
    {
        if(n==-1)
        {
            if(v.size()==0)
                break;
            reverse(all(v));
           int p[100000],l=0;
            for(int i=0;i<v.size();i++)
            {
                int po=upper_bound(p,p+l,v[i])-p;
//                if(p[po]==v[i])
//                po++;
               // cout<<po<<endl;
                p[po]=v[i];
                if(po==l)
                    l++;
            }
            if(ct>1)
                printf("\n");
            printf("Test #%d:\n  maximum possible interceptions: %d\n",ct++,l);
            v.clear();
        }
        else
        v.push_back(n);
    }

}
