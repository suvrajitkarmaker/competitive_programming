#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
#define Unique(x) sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x) to_string(x)
map<string,vector<string> >mp;
map<string,string>path;
map<string,int>chek;
vector< pair<string,string> >v;
string a,b;
void bfs(string so)
{
    queue<string>q;
    q.push(so);
    string x;
    chek[so]=1;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(int i=0; i<mp[x].size(); i++)
        {
            if(chek[mp[x][i]]==0)
            {
               // cout<<mp[x][i]<<endl;
                chek[mp[x][i]]=1;
                path[mp[x][i]]=x;
                q.push(mp[x][i]);
               /* if(mp[x][i]==b)
                {
                    cout<<path["PT"]<<endl;
                }*/
            }
        }
    }
}
int main()
{
     //freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int te,ct=1;
    while(scanf("%d",&te)!=EOF)
    {
        if(ct>1)
            cout<<endl;
        ct++;
        mp.clear();
        v.clear();
        path.clear();
        chek.clear();
        for(int i=0; i<te; i++)
        {
            cin>>a>>b;
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        cin>>a>>b;
        bfs(a);
        int c=0;
        while(path[b]!=a)
        {
            v.push_back(make_pair(path[b],b));
            b=path[b];
            if(path[b]=="")
            {
                c=1;
                printf("No route\n");
                break;
            }
        }
        if(c==1)
        continue;
        v.push_back(make_pair(path[b],b));
        for(int i=v.size()-1; i>=0; i--)
        {
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
    }
}
