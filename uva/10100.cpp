#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
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
#define MAX 100100000
#define eps 1e-15
vector<string>v1,v2;
int dp[1110][1110];
int lcs(int i,int j)
{
    if(i==v1.size()||j==v2.size())
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    int ans=0;
    if(v1[i]==v2[j])
        ans=1+lcs(i+1,j+1);
    else
    {
        int p1=lcs(i+1,j);
        int p2=lcs(i,j+1);
        ans=max(p1,p2);
    }
    dp[i][j]=ans;
    return dp[i][j];

}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    string s1,s2,xx;
    int ct=1;
    while(getline(cin,s1))
    {
        getline(cin,s2);
        v1.clear();
        v2.clear();
        if(ct>=1 && ct<=9)
        printf(" %d. ",ct++);
        else
            printf("%d. ",ct++);
        if(s1.size()==0||s2.size()==0)
        {
            printf("Blank!\n");
            continue;
        }
        xx.clear();
        s1+=".";
        for(int i=0; i<s1.size(); i++)
        {
            if(!(s1[i]>='A' && s1[i]<='Z') && !(s1[i]>='a' && s1[i]<='z') && !(s1[i]>='0' && s1[i]<='9'))
            {
                 if(xx.size()>0)
                v1.push_back(xx);
                xx.clear();
                continue;
            }
            xx+=s1[i];
        }
        xx.clear();
        s2+=".";
        for(int i=0; i<s2.size(); i++)
        {
            if(!(s2[i]>='A' && s2[i]<='Z') && !(s2[i]>='a' && s2[i]<='z') && !(s2[i]>='0' && s2[i]<='9'))
            {
                if(xx.size()>0)
                v2.push_back(xx);
                xx.clear();
                continue;
            }
            xx+=s2[i];
        }
//        for(int i=0;i<v1.size();i++)
//            cout<<v1[i]<<" ";
//            cout<<endl;
//         for(int i=0;i<v2.size();i++)
//            cout<<v2[i]<<" ";
//            cout<<endl;
        CLR(dp,-1);
        printf("Length of longest match: %d\n",lcs(0,0));

    }

}
