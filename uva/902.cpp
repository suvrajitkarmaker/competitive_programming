#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int>mp;
int main()
{
    int n;
    char s[1000000];
    while(scanf("%d %s",&n,s)!=EOF)
    {
        int l=strlen(s),ma=-99999999;
        string res;
        for(int i=0; i<l-n+1; i++)
        {
            string x;
            for(int j=i; j<n+i; j++)
            {
                x+=s[j];
            }
            mp[x]++;
            if(mp[x]>ma)
            {
                ma=mp[x];
                res=x;
            }
            x.clear();
        }
        mp.clear();
        cout<<res<<endl;
    }
}
