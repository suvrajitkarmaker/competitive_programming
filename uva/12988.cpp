#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
#define Unique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x) to_string(x)
#define stringtoint(x) stoll(x)
#define valid(nx,ny,row,col) nx>=0 && nx<row && ny>=0 && ny<col
vector<string>v;
int ct=0;
int tr(int i,int j, int ii)
{
    for(int k=0; k<4; k++)
    {
        if(v[i][k]==ii+48||v[k][j]==ii+48)
            return 0;
    }
    if((i>=0 && i<=1)&&(j>=0 && j<=1))
    {
        for(int k=0;k<=1;k++)
        {
            for(int l=0;l<=1;l++)
            {
                if(v[k][l]==ii+48)
                return 0;
            }
        }
    }
    if((i>=0 && i<=1)&&(j>=2 && j<=3))
    {
        for(int k=0;k<=1;k++)
        {
            for(int l=2;l<=3;l++)
            {
                if(v[k][l]==ii+48)
                return 0;
            }
        }
    }
    if((i>=2 && i<=3)&&(j>=0 && j<=1))
    {
        for(int k=2;k<=3;k++)
        {
            for(int l=0;l<=1;l++)
            {
                if(v[k][l]==ii+48)
                return 0;
            }
        }
    }
    if((i>=2 && i<=3)&&(j>=2 && j<=3))
    {
        for(int k=2;k<=3;k++)
        {
            for(int l=2;l<=3;l++)
            {
                if(v[k][l]==ii+48)
                return 0;
            }
        }
    }
    return 1;
}
void rec(int i,int j)
{
    if(ct==1)
        return;
    if(i==3 && j==4)
    {
        cout<<v[0]<<endl;
        cout<<v[1]<<endl;
        cout<<v[2]<<endl;
        cout<<v[3]<<endl;
        ct=1;
        return;
    }
    if(j==4)
    {
        i++;
        j=0;
    }
    if(v[i][j]=='*')
    {
        for(int ii=1; ii<=4; ii++)
        {
            if(tr(i,j,ii)==1 && v[i][j]=='*')
            {
                v[i][j]=ii+48;
                rec(i,j+1);
                v[i][j]='*';
            }
        }
    }
    else
        rec(i,j+1);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int te;
    scanf("%d",&te);
    for(int j=1; j<=te; j++)
    {
        v.clear();
        string s;
        ct=0;
        for(int i=0; i<4; i++)
        {
            cin>>s;
            v.push_back(s);
        }
        printf("Case #%d:\n",j);
        rec(0,0);

    }
}
