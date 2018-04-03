#include <bits/stdc++.h>
using namespace std;
map<string,int>mp;
long long int lp(long long int y)
{
    long long int a,b,c;
    a=y/4;
    b=y/100;
    c=y/400;
    return a-b+c;
}
int leap(long long int n)
{
    if(n%4==0)
    {
        if(n%100==0)
        {
            if(n%400==0)
                return 1;
            else
                return 0;
        }
        else
            return 1;
    }
    else
        return 0;
}
int main()
{
    int n;
    long long int d,y;
    scanf("%d",&n);
    char s[10000];
    mp["January"]=1;
    mp["February"]=2;
    mp["March"]=3;
    mp["April"]=4;
    mp["May"]=5;
    mp["June"]=6;
    mp["July"]=7;
    mp["August"]=8;
    mp["September"]=9;
    mp["October"]=10;
    mp["November"]=11;
    mp["December"]=12;
    for(int i=0; i<n; i++)
    {
        long long int c=0,d1,d2,y1,y2;
        char s1[50],s2[50];
        scanf("%s %lld , %lld",s1,&d1,&y1);
        scanf("%s %lld , %lld",s2,&d2,&y2);
        if(y1==y2)
        {
            if(leap(y1)==1 && mp[s1]<=2 && (mp[s2]>2||(mp[s2]==2 && d2==29)))
                c++;
        }
        else
        {
            if(leap(y1)==1 && mp[s1]<=2)
                c++;
            if(leap(y2)==1 && (mp[s2]>2||(mp[s2]==2 && d2==29)))
                c++;
            long long int p=lp(y1);
            long long int q=lp(y2-1);
            c+=q-p;
        }
        printf("Case %d: %lld\n",i+1,c);
    }
}
