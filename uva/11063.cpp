#include <bits/stdc++.h>
using namespace std;
vector<int>x,a;
int main()
{
    int t,c=1;
    while(scanf("%d",&t)!=EOF)
    {
        x.clear();
        a.clear();
        int tm,f1=0;
        for(int i=0; i<t; i++)
        {
            scanf("%d",&tm);
            if(tm<=0)
                f1=1;
            a.push_back(tm);
        }
        for(int i=1; i<a.size(); i++)
        {
            if(a[i]<=a[i-1])
            {
                f1=1;
                break;
            }

        }
        if(f1==1)
        {
            //cout<<"dsa"<<endl;
            printf("Case #%d: It is not a B2-Sequence.\n\n",c++);
            continue;
        }
        for(int i=0; i<a.size(); i++)
        {
            for(int j=i; j<a.size(); j++)
            {
                x.push_back(a[i]+a[j]);
            }
        }
        sort(x.begin(),x.end());
        int fo=0;
        for(int i=1; i<x.size(); i++)
        {
            if(x[i]==x[i-1])
            {
                fo=1;
                break;
            }
        }
        if(fo==0)
            printf("Case #%d: It is a B2-Sequence.\n\n",c++);
        else
            printf("Case #%d: It is not a B2-Sequence.\n\n",c++);
    }

}
