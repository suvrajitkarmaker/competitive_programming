#include <bits/stdc++.h>
using namespace std;
map<string,int>mp;
int main()
{
    string s,n,tp;
    while(cin>>s)
    {
        int c1=0;
        for(int i=0; i<s.size(); i++)
        {
            for(int j=i; j<s.size(); j++)
            {
                n+=s[j];
                tp=n;
                reverse(tp.begin(),tp.end());
                //cout<<tp<<endl;
                if(tp==n && mp[tp]==0)
                {
                    mp[tp]=1;
                    c1++;
                }
            }
            n.clear();
            tp.clear();
        }
        printf("The string '");
        cout<<s;
        printf("' contains %d palindromes.\n",c1);
        mp.clear();
    }
}
