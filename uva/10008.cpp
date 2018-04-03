#include <bits/stdc++.h>
using namespace std;
map<char,int>mp;
int a[100000];
int main()
{
    string s;
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0; i<n; i++)
    {
        getline(cin,s);

        for(int j=0; j<s.size(); j++)
        {
            if(s[j]>='A' && s[j]<='Z')
                mp[s[j]]++;
            else if(s[j]>='a' && s[j]<='z')
                mp[s[j]-32]++;
        }
    }
    int a[50];
    for(int i=65; i<=90; i++)
        a[i-65]=mp[i];
    sort(a,a+26,greater<int>());
    for(int i=0; i<26; i++)
    {
        if(a[i]!=0)
        {
             for(int j=65;j<=90;j++)
             {
                 if(mp[j]==a[i] && mp[j]!=0)
                 {
                     printf("%c %d\n",j,a[i]);
                     mp[j]=0;
                 }
             }
        }
    }
}
