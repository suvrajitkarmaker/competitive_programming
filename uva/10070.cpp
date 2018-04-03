#include <bits/stdc++.h>
using namespace std;
int st(string s,int n)
{
    int d=s.size(),m=0;
    for(int i=0; i<d; i++)
    {
        m=((m*10)+(s[i]-48))%n;
    }
    if(m==0)
        return 0;
    else
        return 1;
}
int main()
{
    int n,c=0;
    string x;
    while(cin>>x)
    {
        if(c>0)
            printf("\n");
        if((st(x,4)==0 && st(x,100)==1)||(st(x,4)==0&& st(x,100)==0 && st(x,400)==0))
        {
            printf("This is leap year.\n");
            if(st(x,15)==0)
                printf("This is huluculu festival year.\n");
            if(st(x,55)==0)
                printf("This is bulukulu festival year.\n");
        }
        else if(st(x,15)==0)
            printf("This is huluculu festival year.\n");
        else
            printf("This is an ordinary year.\n");
        c++;
    }
}
