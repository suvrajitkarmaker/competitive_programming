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
#define MAX 10010
#define eps 1e-15
#define mod 1000000009
#define PII pair<int, int>
priority_queue<PII, vector<PII>, greater<PII> > q;
vector<string>v;

int main()
{
   // READ("input.txt");
    // WRITE("output.txt");
    int te;
    cin>>te;
    getchar();
    string s;
    vector<ll>a;
    while(te--)
    {
        a.clear();
        getline(cin,s);
        ll x=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                if(x>0)
                a.push_back(x);
                x=0;
            }
            else
                x=x*10+s[i]-48;
        }
        if(x>0)
        a.push_back(x);

        ll mx=1;
        for(int i=0;i<a.size();i++)
        {
            //printf("%d ",a[i]);
            for(int j=i+1;j<a.size();j++)
            {

                mx=max(mx,__gcd(a[i],a[j]));
            }
        }
        printf("%d\n",mx);
    }
}
