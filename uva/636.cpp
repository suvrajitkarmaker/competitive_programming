#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
#define Unique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x) to_string(x)
#define valid(i,y,row,col) i>=0 && i<row && j>=0 && j<col
char s[1000];
int  l;
ll fn(int bs)
{
    ll pw,sum=0,po=1;
    for(int j=0;j<l;j++,po*=bs)
    {
        pw=(s[j]-48)*po;
        sum+=pw;
    }
    return  sum;

}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll sq,root;
    while(1)
    {
        scanf("%s",s);
        if(strcmp(s,"0")==0)
        break;
        l=strlen(s);
        reverse(s,s+l);
        int mx=-1;
        for(int i=0;i<l;i++)
        {
            if((s[i]-48)>mx)
            mx=(s[i]-48);
        }
        for(int i=mx+1;i<=100;i++)
        {
            sq=fn(i);
            //cout<<sq<<endl;
            root=sqrt(sq);
            if(root*root==sq)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
}
