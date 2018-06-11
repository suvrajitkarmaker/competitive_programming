#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
#define Unique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x) to_string(x)
#define valid(i,y,row,col) i>=0 && i<row && j>=0 && j<col
int fx[]= {1,-1,-2,-2,-1,1,2,2};
int fy[]= {2,2,1,-1,-2,-2,-1,1};
int mi=99999990,tc[20][20],fl=0;
vector<string>s;
char ini[20][20]= {"11111","01111","00 11","00001","00000"};
int milche()
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(ini[i][j]!=s[i][j])
                return 0;
        }
    }
    return 1;
}
void BT(int i,int j,int ct,int op)
{
    /*for(int pr=0; pr<5; pr++)
        cout<<s[pr]<<endl;
    cout<<endl;*/
    if(mi!=-1)
    return;
    if(ct==op)
    {
        if(milche()==1)
        {
            mi=op;

        }
        return;
    }

    for(int st=0; st<8; st++)
    {

        int ii=i+fx[st];
        int jj=j+fy[st];
        if(valid(ii,jj,5,5)==1)
        {
            //tc[i][j]=1;
            //cout<<s[i][j]<<"sk"<<s[ii][jj]<<endl;
            swap(s[i][j],s[ii][jj]);
            BT(ii,jj,ct+1,op);
            //tc[i][j]=0;
            swap(s[i][j],s[ii][jj]);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tes,xi,xj;
    cin>>tes;
    getchar();
    while(tes--)
    {
        string tm;
        s.clear();
        mi=-1;
        for(int i=0; i<5; i++)
        {
            getline(cin,tm);
            s.push_back(tm);

        }

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                if(s[i][j]==' ')
                {
                    xi=i;
                    xj=j;
                }
            }
        }
        for(int op=0; op<=10; op++)
        {
            BT(xi,xj,0,op);
            if(mi!=-1)
            break;

        }
        if(mi==-1)
            printf("Unsolvable in less than 11 move(s).\n");
        else
            printf("Solvable in %d move(s).\n",mi);
    }
}
