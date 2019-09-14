#include <bits/stdc++.h>
using namespace std;

vector<int>v;
int main()
{
    int n,q,xx,tm,ct=1;
    char cr[10];
    while(scanf("%d %d",&n,&q) &&n &&q)
    {
        v.clear();
        for(int i=1; i<=min(n,q); i++)
        {
            v.push_back(i);
        }
        printf("Case %d:\n",ct++);
        for(int i=1; i<=q; i++)
        {
            scanf("%s",&cr);
            if(cr[0]=='N')
            {
                xx=v[0];
                printf("%d\n",v[0]);
                v.erase(v.begin());
                v.push_back(xx);
                //cout<<v.size()<<endl;
            }
            else
            {
                scanf("%d",&tm);

                for(int j=0; j<v.size(); j++)
                {
                    if(v[j]==tm)
                    {
                        v.erase(v.begin()+j);
                        break;
                    }
                }
                v.insert(v.begin(),tm);

            }
        }
    }
}
