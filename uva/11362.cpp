#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int>mp;
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        char s[n][100];
        for(int j=0;j<n;j++)
        {
            scanf("%s",s[j]);
            mp[s[j]]=1;
        }
        int c1=0;
        for(int j=0;j<n;j++)
        {
            int l=strlen(s[j]);
            string tm;
            for(int k=0;k<l;k++)
            {
                tm+=s[j][k];
                if(mp[tm]==1 && k<l-1)
                {
                    c1=1;
                    break;
                }
            }
            tm.clear();
        }
        if(c1==0)
            printf("YES\n");
        else
            printf("NO\n");
        mp.clear();
    }
}
