#include <bits/stdc++.h>
using namespace std;
int num[]= {1,4,5,9,10,40,50,90,100};
char rom[100][100]= {"I","IV","V","IX","X","XL","L","XC","C"};
int rt[200][10];
void countroman(string s,int n)
{
    int t;
    for(int i=0; i<s.size(); i++)
    {

        if(s[i]=='I')
            rt[n][0]++;
        else if(s[i]=='V')
            rt[n][1]++;
        else if(s[i]=='X')
            rt[n][2]++;
        else if(s[i]=='L')
            rt[n][3]++;
        else if(s[i]=='C')
            rt[n][4]++;
    }
    rt[n][0]+=rt[n-1][0];
    rt[n][1]+=rt[n-1][1];
    rt[n][2]+=rt[n-1][2];
    rt[n][3]+=rt[n-1][3];
    rt[n][4]+=rt[n-1][4];
}
string degit_roman(int x)
{
    string s;
    if(x==100)
    {
        s+="C";
        x=0;
    }
    while(x>0)
    {
        for(int i=0; i<9; i++)
        {
            if(x>=num[i] && x<num[i+1])
            {
                s+=rom[i];
                x-=num[i];
            }
        }

    }
    return s;
}
int main()
{
    string s;
    for(int i=1; i<=100; i++)
    {
        s=degit_roman(i);
        countroman(s,i);
    }
    int n;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,rt[n][0],rt[n][1],rt[n][2],rt[n][3],rt[n][4]);
    }

}
