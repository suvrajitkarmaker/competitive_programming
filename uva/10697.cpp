#include <bits/stdc++.h>
using namespace std;
unsigned long long int x[1000000],base=10000007;
unsigned long long int ha(string a)
{
    unsigned long long int value=0;
    int d=a.length();
    for(int i=0; i<d; i++)
    {
        value=(value*base)+a[i];
        x[i]=value;
    }
}
int main()
{
    string a,b;
    int t,tt,te;
    scanf("%d",&tt);
    for(int k=0; k<tt; k++)
    {
        cin>>b;
        ha(b);
        scanf("%d",&te);
        for(int j=0; j<te; j++)
        {
            cin>>a;
            unsigned long long int y,value=0,mul=1;
            int d=a.length();
            for(int i=0; i<d; i++)
            {
                value=(value*base)+a[i];
                mul*=base;
            }
            t=0;
            for(int i=b.length()-1; i>=d-1; i--)
            {
                if((i-d)<0)
                    y=x[i];
                else
                    y=x[i]-(x[i-d]*mul);
                if(y==value)
                {
                    t=1;
                    break;
                }
            }
            if(t==1)
                printf("y\n");
            else
                printf("n\n");
        }
    }

}
