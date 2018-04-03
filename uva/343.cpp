#include <bits/stdc++.h>
using namespace std;
int ba1,ba2;
int chek(string s)
{
    int x,m=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='A' && s[i]<='Z')
            x=s[i]-55;
        else if(s[i]>='a' && s[i]<='z')
            x=s[i]-87;
        else
            x=s[i]-48;
        if(x>m)
            m=x;
    }
    return m;
}
long long int base10(string s,int b)
{
    long long int sum=0,x,tem;
    for(int i=0,j=s.size()-1; i<s.size(); i++,j--)
    {
        if(s[i]>='A' && s[i]<='Z')
            x=s[i]-55;
        else if(s[i]>='a' && s[i]<='z')
            x=s[i]-87;
        else
            x=s[i]-48;
        tem=pow(b,j)+0.5;
        sum+=x*tem;
    }
    return sum;
}
int result(string s1, string s2)
{
    if(chek(s1)==0 && chek(s2)==0)
    {
        ba1=2;
        ba2=2;
        return 0;
    }
    long long int x;
    int c1=chek(s1)+1,c2=chek(s2)+1;
    int ss1[50],ss2[50],bb1[50],bb2[50];
    int j=0,k=0;
    for(int i=c1; i<=36; i++,j++)
    {
        ss1[j]=base10(s1,i);
        bb1[j]=i;
    }
    for(int i=c2,j=0; i<=36; i++,k++)
    {
        ss2[k]=base10(s2,i);
        bb2[k]=i;
    }
    for(int i=0; i<j; i++)
    {
        for(int l=0; l<k; l++)
        {
            if(ss1[i]==ss2[l])
            {
                ba1=bb1[i];
                ba2=bb2[l];
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    char s1[1000],s2[10000];
    int b1,b2;
    while(scanf("%s %s",s1,s2)!=EOF)
    {
        if(result(s1,s2)==0)
            printf("%s (base %d) = %s (base %d)\n",s1,ba1,s2,ba2);
        else
            printf("%s is not equal to %s in any base 2..36\n",s1,s2);
    }
}
