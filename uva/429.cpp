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
vector<string>in;
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
int onepositon(string p,string q)
{
    int cot=0;
    for(int i=0; i<p.size(); i++)
    {
        if(p[i]==q[i])
        {
            cot++;
        }
    }
    if(cot+1==p.size())
        return 1;
    return 0;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int te,ct=1;
    cin>>te;
    for(int ii=1;ii<=te;ii++)
    {
        if(ii>1)
        cout<<endl;
        mp.clear();
        in.clear();
        while(cin>>a && a!="*")
        {
            in.push_back(a);
        }
        //duplicate thakte pare
        for(int i=0; i<in.size(); i++)
        {
            for(int j=0; j<in.size(); j++)
            {
                if(in[i]!=in[j] && in[i].size()==in[j].size() && onepositon(in[i],in[j])==1)
                {
                    mp[in[i]].push_back(in[j]);
                }
            }
        }
        string al;
        cin.ignore();
        while(getline(cin,al) && al.size())
        {
            stringstream ss(al);
            ss>>a>>b;
            if(a==b)
            {
                cout<<a<<" "<<b<<" "<<0<<endl;
                continue;
            }
            path.clear();
            chek.clear();
            bfs(a);
            string tb=b;
            int c=0;

            while(path[b]!=a)
            {
                b=path[b];
                c++;
            }
            cout<<a<<" "<<tb<<" "<<c+1<<endl;
        }
    }
}
