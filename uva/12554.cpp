#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[1000][1000]= {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
    char s[1000][1000];
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%s",s[i]);
    }
    int j=0,k=0,i=0;
    int x=n;
    if(x%16!=0)
    {
        x=x/16;
        x=(x*16)+16;
    }
    while(k<x)
    {
        printf("%s: %s\n",s[j++],a[i++]);
        if(j==n)
            j=0;
        k++;
        if(i%16==0)
            i=0;

    }
}
