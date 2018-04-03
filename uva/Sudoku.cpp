#include <bits/stdc++.h>
using namespace std;
char s[20][20];
char ss[20][20];
int use[20];
int conflick(int i,int j,int n)
{
    for(int k=0; k<4; k++)
        if(s[i][k]==n+48)
        {
            return 1;
        }
    for(int k=0; k<4; k++)
        if(s[k][j]==n+48)
        {
            return 1;
        }
    if((i>=0 && i<=1) && (j>=0 && j<=1))
    {
        for(int k=0; k<=i; k++)
        {
            for(int l=0; l<=j; l++)
                if(s[k][l]==n+48)
                    return 1;
        }
    }
    if((i>=0 && i<=1) && (j>=2 && j<=3))
    {
        for(int k=0; k<=i; k++)
        {
            for(int l=2; l<=j; l++)
                if(s[k][l]==n+48)
                    return 1;
        }
    }
    if((i>=2 && i<=3) && (j>=0 && j<=1))
    {
        for(int k=2; k<=i; k++)
        {
            for(int l=0; l<=j; l++)
                if(s[k][l]==n+48)
                    return 1;
        }
    }
    if((i>=2 && i<=3) && (j>=2 && j<=3))
    {
        for(int k=2; k<=i; k++)
        {
            for(int l=2; l<=j; l++)
                if(s[k][l]==n+48)
                    return 1;
        }
    }
    return 0;
}
void backtrack(int p,int t,int n)
{
    if(n>4)
        return;
    if(p>=4 && t==3)
    {
        for(int i=0; i<4; i++)
        {
            printf("%s\n",s[i]);
        }
        cout<<endl;
        return;
    }
    if(p>=4)
        return;



    for(int i=0; i<4; i++)
    {
        if(ss[i][p]>='1' && ss[i][p]<='4')
            backtrack(p+1,i,n);
        else if(use[i]==0 && conflick(i,p,i)==0)
        {
            s[i][p]=i+48;
            use[i]=1;
            backtrack(p+1,i,i+1);
            s[i][p]='*';
            use[i]=0;

        }
    }
}
int main()
{
    for(int i=0; i<4; i++)
    {
        scanf("%s",s[i]);
        strcpy(ss[i],s[i]);
    }
    backtrack(0,0,1);
}
