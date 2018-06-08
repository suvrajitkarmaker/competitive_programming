#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define PI acos(-1.0)
#define all(x) (x).begin(), (x).end()
#define Unique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x) to_string(x)
#define stringtoint(x) stoll(x)
#define valid(nx,ny,row,col) nx>=0 && nx<row && ny>=0 && ny<col
int n,mx=-1;
vector<string>v;
int check(int i,int j)
{
    for(int k=j; k<n && v[i][k]!='X'; k++)
    {
        if(v[i][k]=='o')
            return 0;
    }
    for(int k=j; k>=0 && v[i][k]!='X'; k--)
    {
        if(v[i][k]=='o')
            return 0;
    }
    for(int k=i; k<n && v[k][j]!='X'; k++)
    {
        if(v[k][j]=='o')
            return 0;
    }
    for(int k=i; k>=0 && v[k][j]!='X'; k--)
    {
        if(v[k][j]=='o')
            return 0;
    }
    return 1;

}
void btrack(int i,int j)
{
    if(i==n-1 && j==n)
    {
        int ct=0;
        for(int k=0; k<n; k++)
        {
            for(int l=0; l<n; l++)
            {
                if(v[k][l]=='o')
                    ct++;
            }
        }
        mx=max(ct,mx);
        return;
    }
    if(j==n)
    {
        i++;
        j=0;
    }
    if(v[i][j]=='X')
        btrack(i,j+1);
    else if(check(i,j)==1)
    {
        v[i][j]='o';
        btrack(i,j+1);
        v[i][j]='.';
        btrack(i,j+1);
    }
    else
    {
        btrack(i,j+1);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        v.clear();
        string s;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            v.push_back(s);
        }//
        mx=-1;
        btrack(0,0);
        cout<<mx<<endl;
    }
}
