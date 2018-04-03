#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[100],temp[100],re[50][100];

    while(scanf("%s",s)!=EOF)
    {
        strcpy(temp,s);
        strcpy(re[10],s);
        int l=strlen(s);
        for(int i=9; i>=0; i--)
        {
            prev_permutation(s,s+l);
            strcpy(re[i],s);

        }
        for(int i=11; i<=20; i++)
        {
            next_permutation(temp,temp+l);
            strcpy(re[i],temp);
        }
        int mi,micout=0,r;
        char result[1000];
        for(int i=0; i<21; i++)
        {
            l=strlen(re[i]);
            mi=999999;
            for(int j=1; j<l; j++)
            {
                if(abs(re[i][j]-re[i][j-1])<mi)
                    mi=abs(re[i][j]-re[i][j-1]);
            }
            if(mi>micout)
            {
                r=mi;
                micout=mi;
                strcpy(result,re[i]);
            }
        }
        printf("%s%d\n",result,r);
    }
}
