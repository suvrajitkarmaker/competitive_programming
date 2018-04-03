#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ss,bb,x1,y1;
    while(scanf("%d %d",&ss,&bb))
    {
        if(ss==0 && bb==0)
            break;
        set<int>s;
        // set <int, greater <int> > :: iterator itr;
        for(int i=0; i<=ss+1; i++)
        {
            s.insert(i);
        }
        for(int i=0; i<bb; i++)
        {
            scanf("%d %d",&x1,&y1);
            for(int i=x1;i<=y1;i++)
                s.erase(i);
            auto lo=s.lower_bound(x1), up=s.upper_bound(y1);
            lo--;
            //cout<<*lo<<" "<<*up<<endl;
            if(*lo==0)
                printf("* ");
            else
                printf("%d ",*lo);
            if(*up==ss+1)
                printf("*\n");
            else
                printf("%d\n",*up);
        }
        printf("-\n");
    }
}
