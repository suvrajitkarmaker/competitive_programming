#include <bits/stdc++.h>
using namespace std;
int chek(string s,int b)
{
    int x;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='A' && s[i]<='Z')
            x=s[i]-55;
        else if(s[i]>='a' && s[i]<='z')
            x=s[i]-87;
        else
            x=s[i]-48;
        if(x>=b)
            return 1;
    }
    return 0;
}
void base1_base2(string s,int b1,int b2)
{
    if(s=="0")
        printf("0 base %d = 0 base %d\n",b1,b2);
    else
    {
        string ss=s;
        long long int sum=0,x,tem;
        for(int i=0,j=s.size()-1; i<s.size(); i++,j--)
        {
            if(s[i]>='A' && s[i]<='Z')
                x=s[i]-55;
            else if(s[i]>='a' && s[i]<='z')
                x=s[i]-87;
            else
                x=s[i]-48;
            tem=pow(b1,j)+0.5;
            sum+=x*tem;
        }
        char r[10000];
        int i=0;
        while(sum>0)
        {
            x=sum%b2;
            if(x>=10 && x<=15)
                r[i++]=x+55;
            else
                r[i++]=x+48;
            sum/=b2;
        }
        r[i]='\0';
        reverse(r,r+i);
        cout<<ss;
        printf(" base %d = %s base %d\n",b1,r,b2);
    }

}
int main()
{
    char s[1000];
    int b1,b2;
    while(scanf("%d %d %s",&b1,&b2,s)!=EOF)
    {
        if(chek(s,b1)==1)
            printf("%s is an illegal base %d number\n",s,b1);
        else
        {
            base1_base2(s,b1,b2);
        }
    }
}
