#include <bits/stdc++.h>
using namespace std;
long long int c[10000],s[100000000];
bool re1[1100000000];

int main()
{
    c[0]=0;
    for(int i=1; i<=1000; i++)
    {
        c[i]=i*i*i;
    }
    int k=0;
    s[k++]=0;
    for(int i=1; i<=1000; i++)
    {
        for(int j=i+1; j<=1000; j++)
        {
            if((c[i]+c[j])>1000100000)
                continue;
            if(re1[c[i]+c[j]]==0)
                re1[c[i]+c[j]]=1;
            else
            {
                s[k++]=c[i]+c[j];

            }
        }
    }
    sort(s,s+k);
    long long int u,p;
    while(scanf("%lld %lld",&u,&p)!=EOF)
    {
        int w=0;
        for(int i=0; i<k; i++)
        {
            if(s[i]>=u && s[i]<=(u+p) && (i>0 && s[i]!=s[i-1]))
            {
                w=1;
                printf("%lld\n",s[i]);
            }
        }
        if(w==0)
            printf("None\n");
    }
}
