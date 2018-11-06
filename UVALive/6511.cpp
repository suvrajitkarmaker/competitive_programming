#include <bits/stdc++.h>
using namespace std;
int gp[100100];
int mark1[100100],mark2[100100],f;
map<int,int>mp;
void dfs2(int so)
{
    //cout<<so<<"ss ";
    if(mark2[so]==1||f==1)
    {
        f=1;
        return;
    }
    //mp[so]=1;
    mark2[so]=1;
    dfs2(gp[so]);
}
void dfs1(int so)
{
    //cout<<so<<" ";
    if(mark2[so]==1)
        return;
    if(mark1[so]==1)
    {
        f=0;
        dfs2(so);
        //cout<<endl;
        return;
    }
    mark1[so]=1;
    dfs1(gp[so]);
    //cout<<so<<endl;
    mark1[so]=0;
}
int main()
{
    int n,te;
    scanf("%d",&te);
    while(te--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&gp[i]);
        }
        memset(mark1,0,sizeof(mark1));
        memset(mark2,0,sizeof(mark2));
        mp.clear();
        for(int i=1; i<=n; i++)
        {
            //cout<<i<<endl;
            dfs1(i);
            //mark1[i]=0;
        }
        int ct=0;
        for(int i=1;i<=n;i++)
        {
            if(mark2[i]==0)
                ct++;
        }
        cout<<ct<<endl;
    }

}
