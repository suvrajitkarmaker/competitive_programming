#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[150];
    char s[10000];
    while(scanf("%s",s)!=EOF)
    {
        int l=strlen(s);
        memset(a,0,sizeof(a));
        for(int i=0;i<l;i++)
        {
            a[s[i]]++;
        }
        int n[1000],m[10000],j=0;
        for(int i=128;i>=32;i--)
        {
            if(a[i]>0)
            {
                m[j]=i;
                n[j]=a[i];
                j++
            }
        }
        need structure sort :3
    }
}
