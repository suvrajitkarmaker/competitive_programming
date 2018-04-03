#include <bits/stdc++.h>
using namespace std;
int com(string n,string m)
{
    if(n>m)
        return 1;
    else
        return 0;
}
int main()
{
    int n,t;
    scanf("%d",&t);
    for(int k=1; k<=t; k++)
    {
        int a[10],b[10];
        char s[1000][1000];
        for(int i=0; i<10; i++)
        {
            scanf("%s %d %d",s[i],&a[i],&b[i]);
        }
        int key1,key2,key3,j;
        char tt[1000];
        for(int i=1; i<10; i++)
        {
            key1=a[i];
            key2=b[i];
            strcpy(tt,s[i]);
            j=i-1;
            while(j>=0 && ((a[j]<key1)||(a[j]==key1 && b[j]>key2)||(a[j]==key1 && b[j]==key2 && com(s[j],tt)==1)))
            {
                a[j+1]=a[j];
                b[j+1]=b[j];
                strcpy(s[j+1],s[j]);
                j--;
            }
            a[j+1]=key1;
            b[j+1]=key2;
            strcpy(s[j+1],tt);
        }
        string p[1000],q[1000];
        for(int i=0; i<10; i++)
        {
            if(i>=0 && i<=4)
                p[i]=s[i];
            if(i>=5 && i<=9)
                q[i-5]=s[i];
        }
        sort(p,p+5);
        sort(q,q+5);
        printf("Case %d:\n",k);
        printf("(");
        for(int i=0; i<4; i++)
            cout<<p[i]<<", ";
        cout<<p[4]<<")"<<endl;
        printf("(");
        for(int i=0; i<4; i++)
            cout<<q[i]<<", ";
        cout<<q[4]<<")"<<endl;
    }

}
