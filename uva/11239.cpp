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

struct st
{

    string s;
    int x;
} ar[1000000];

bool cmp(st A,st B)
{
    if(A.x==B.x)
        return A.s<B.s;

    return A.x>B.x;
}


map<string,int>prj,sto,own,bal;
map<string,string>mp;
int main()
{
//    READ("input.txt");
//    WRITE("output.txt");
    string s,last;
    int in=0;
    while(getline(cin,s))
    {
        int ct=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]>='a' && s[i]<='z')
                continue;
            ct++;
        }
        if(s[0]=='1')
        {
            for(int i=0; i<in; i++)
            {
                ar[i].x=prj[ar[i].s];
            }


            sort(ar,ar+in,cmp);

            for(int i=0; i<in; i++)
            {
                cout<<ar[i].s<<" "<<ar[i].x<<endl;
            }
            in=0;
            prj.clear();
            sto.clear();
            own.clear();
            mp.clear();
            bal.clear();
        }
        else if(s[0]=='0')
            break;
        else if(ct==s.size())
        {
            last=s;
            ar[in++].s=last;
            own.clear();
        }
        else
        {
            if(own[s]==0)
            {
                own[s]=1;
                if(sto[s]==0)
                {
                    sto[s]=1;
                    mp[s]=last;
                    prj[last]++;
                }
                else
                {
                    if(bal[s]==0)
                        prj[mp[s]]--;
                    bal[s]=1;
                }

            }
        }
    }

}
