#include <bits/stdc++.h>
using namespace std;
string res[1000000],re[1000000];
string sum(string a, string b)
{
    string c;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int i=0;
    int s=0;
    int lim=max(a.size(), b.size());
    while(i<lim)
    {
        if(i<a.size()) s+=a[i]-'0';
        if(i<b.size()) s+=b[i]-'0';
        c+=(s%10+'0');
        s/=10;
        i++;
    }
    while(s)
    {
        c+=(s%10+'0');
        s/=10;
    }
    reverse(c.begin(), c.end());
    return c;
}

int main()
{
    res[0]="1";
    res[1]="1";
    for(int i=2;i<=4000;i++)
    {
        res[i]=sum(res[i-1],res[i-2]);
    }
    int j=1;
    for(int i=1;i<=4000;i+=2,j++)
        re[j]=res[i];
    int te;
    while(scanf("%d",&te)&&te)
    {
        cout<<re[te]<<endl;
    }

}
