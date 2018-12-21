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
#define valid(nx,ny,row,col)    nx>0 && nx<=row && ny>0 && ny<=col
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
#define eps 1e-15
vector<string>v;
map<string,int>mp;
int main()
{
//    READ("input.txt");
//     WRITE("output.txt");
    int te,ct=0;
    scanf("%d",&te);

    string s;
    cin.ignore(2);
    while(te--)
    {
        //cout<<te<<endl;
        mp.clear();
        v.clear();

        while(getline(cin,s) && s.size())
        {
            mp[s]++;
            v.push_back(s);
        }
       // getchar();

        double l=v.size();
        Unique(v);
        if(ct>0)
            printf("\n");
        ct++;
        for(int i=0; i<v.size(); i++)
        {
            cout<<v[i]<<" ";
            //cout<<(100.0*mp[v[i]])/l<<endl;
            printf("%0.4f\n",(100.0*mp[v[i]])/l);
        }
    }


}
