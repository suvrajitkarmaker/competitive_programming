#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
#define Unique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x) to_string(x)
#define valid(i,y,row,col) i>=0 && i<row && j>=0 && j<col
ll fib[300],l=0,n,nn;
vector<ll>v,p;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //fib[0]=1;
    fib[1]=1;
    fib[2]=2;
    for(l=3; ;l++)
    {
        fib[l]=fib[l-1]+fib[l-2];
        //cout<<fib[l]<<endl;
        if(fib[l]>5000000000000000000)
        break;
    }
    int ct=1;
    while(scanf("%lld",&n)!=EOF)
    {

        v.clear();
        p.clear();
        if(n==0)
        {
            printf("0\n0 \n0 \n\n");
            continue;
        }
        nn=n;
        for(int i=l;i>=1;i--)
        {
            if(fib[i]<=n)
            {
                v.push_back(i);
                p.push_back(fib[i]);
                n-=fib[i];
            }
            if(n==0)
            break;
        }

        printf("%lld\n",nn);
        for(int i=0;i<v.size();i++)
        printf("%lld ",v[i]);
        printf("\n");
        for(int i=0;i<p.size();i++)
        printf("%lld ",p[i]);

        printf("\n\n");
    }
}
