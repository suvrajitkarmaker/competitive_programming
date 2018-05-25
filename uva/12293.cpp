#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
#define Unique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x) to_string(x)
#define stringtoint(x) stoll(x)
#define valid(nx,ny,row,col) nx>=0 && nx<row && ny>=0 && ny<col
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t,x,y,d;
    while(scanf("%lld",&t))
    {

        if(t==0)
            break;
        int f=0;
        for(int i=1;i<=t;i=(i*2)+1)
        {
            if(i==t)
            f=1;
        }
        if(f==0)
        printf("Alice\n");
        else
        printf("Bob\n");

    }
}
