#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
#define Unique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x) to_string(x)
#define stringtoint(x) stoll(x)
#define valid(nx,ny,row,col) nx>=0 && nx<row && ny>=0 && ny<col
#define MAX 100100
vector<int>v;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,x,y,te=1,se;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        v.clear();
        printf("Set #%d\n",te++);
        se=0;
        int a,sum=0;
        for(int i=0; i<m; i++)
        {
            scanf("%d",&a);
            v.push_back(a);
            sum+=a;
        }
        for(int i=m; i<n; i++)
            v.push_back(0);
        sort(all(v));
        double avg=sum/(double)n,res=0.0;
        int l=v.size();
        while(n*2!=m)
        {
            n--;
            m--;
            printf(" %d:",se++);
            if(v[l-1]!=0)
                printf(" %d\n",v[l-1]);
            else
                printf("\n");
            l--;
            res+=fabs(v[l]-avg);
            if(n==0)
            break;
        }
        for(int i=0,j=m-1; i<j; i++,j--)
        {
            printf(" %d:",se++);
            if(v[i])
                printf(" %d",v[i]);
            if(v[j]!=0)
                printf(" %d",v[j]);
            printf("\n");

            res+=fabs(v[i]+v[j]-avg);
        }
        printf("IMBALANCE = %0.5lf\n\n",res);


    }
}
