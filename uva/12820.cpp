#include <bits/stdc++.h>
using namespace std;
map<char,int>mp;
int main()
{
    int t,lp=1;
    while(scanf("%d",&t)!=EOF)
    {
        int c=0;
        for(int i=0; i<t; i++)
        {
            char x[50];
            scanf("%s",x);
            int l=strlen(x);
            mp.clear();
            for(int i=0; i<l; i++)
            {
                mp[x[i]]++;
            }
            int f=0,co=0;
            for(int i=97; i<=122; i++)
            {
                if(mp[i]==0)
                {
                    co++;
                    continue;
                }
                for(int j=97; j<=122; j++)
                {
                    if(i==j)
                        continue;
                    if(mp[i]==mp[j])
                    {
                        f=1;
                        break;
                    }
                }
                if(f==1)
                    break;
            }
            if(f==0 &&co<=24)
                c++;
        }
        printf("Case %d: %d\n",lp++,c);

    }
}
