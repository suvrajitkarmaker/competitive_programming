#include <bits/stdc++.h>
using namespace std;
vector<int>v;
int mp[30005];
int main()
{
    int n,co=1;
    while(scanf("%d",&n)!=EOF)
    {
        int a[n],f=0;
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(int i=1; i<n; i++)
        {
            if(a[i]<=a[i-1])
            {
                f=1;
                break;
            }
        }
        if(a[0]<1)
            f=1;

        printf("Case #%d:",co++);
        for(int i=0; i<n; i++)
            printf(" %d",a[i]);
        printf("\n");
        if(f==0)
        {
            if(n==2)
                f=0;
            else if(n==3 && a[0]+a[1]!=a[2])
                f=0;
            else if(n==3 && a[0]+a[1]==a[2])
                f=1;
            else
            {
                v.clear();
                memset(mp,0,sizeof(mp));
                v.push_back(a[0]);
                v.push_back(a[1]);
                v.push_back(a[0]+a[1]);
                mp[a[1]+a[0]]=1;
                f=0;
                for(int i=3; i<n; i++)
                {
                    int t=v.size();
                    v.push_back(a[i-1]);
                    for(int j=0; j<t; j++)
                    {
                        v.push_back(v[j]+a[i-1]);
                        mp[v[j]+a[i-1]]=1;
                    }
                    if(mp[a[i]]==1)
                    {
                        f=1;
                        break;
                    }
                }
            }
        }
        if(f==0)
            printf("This is an A-sequence.\n");
        else
            printf("This is not an A-sequence.\n");

    }
}
