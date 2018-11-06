#include <bits/stdc++.h>
using namespace std;
vector<int>v[10];
int res[10][10],trak[10],mx;
void bt(int po,int sum)
{
    mx=max(mx,sum);
    if(po==6)
        return;

    for(int i=1;i<=6;i++)
    {
        if(trak[i]==0)
        {
            trak[i]=1;
            bt(po+1,sum+res[po][i]);
            trak[i]=0;
        }
    }
}
int main()
{
    int x,co=1;
    while(1)
    {
        int ct=0,fl=0;
        for(int i=0;i<6;i++)
            v[i].clear();
        for(int i=0; i<6; i++)
        {
            for(int j=0; j<5; j++)
            {
                if(j==0)
                    scanf("%d",&x);
                else
                    scanf("-%d",&x);
                    if(x==0)
                        ct++;
                v[i].push_back(x);
            }
            if(i==0 && ct==5)
            {
                fl=1;
                break;
            }
        }
        if(fl==1)
            break;
        memset(res,0,sizeof(res));
        memset(trak,0,sizeof(trak));
        for(int i=0; i<6; i++)
        {
            for(int j=0; j<5; j++)
            {
                res[i][v[i][j]]+=v[i][j];
            }
            // cout<<endl;
        }
        mx=-1;
        bt(0,0);
        if(mx>=63)
            mx+=35;
        printf("Case %d: %d\n",co++,mx);
    }
}
