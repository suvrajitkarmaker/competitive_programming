#include <bits/stdc++.h>
using namespace std;
vector<string>s;
vector<string>ss;
int main()
{
    string t;

    while(cin>>t&& t!="#")
        s.push_back(t);
    t.clear();
    getchar();
    while(getline(cin,t) && t!="#")
        ss.push_back(t);

    t.clear();
    for(int i=0; i<ss.size(); i++)
    {
        int c1=0;
        for(int j=0; j<s.size(); j++)
        {
            int c=0;
            int num[100];
            memset(num,0,sizeof(num));
            for(int k=0; k<s[j].size(); k++)
            {

                for(int l=0; l<ss[i].size(); l++)
                {
                    if(s[j][k]==ss[i][l] && num[l]==0)
                    {
                        c++;
                        num[l]=1;
                        break;
                    }
                }
            }
            if(c==s[j].size())
                c1++;
        }
        cout<<c1<<endl;
    }
    return 0;
}
