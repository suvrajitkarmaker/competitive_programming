#include <bits/stdc++.h>
using namespace std;
int main()
{
    string x[100][100];
    string s;
    int berhoyejabe=0;
    while(1)
    {
        int k=0;
        while(cin>>s)
        {
            if(s[0]=='#')
            {
                berhoyejabe=1;
                break;
            }
            if(s[0]=='e')
                break;
            string tp;
            for(int i=0,j=0; i<s.size(); i++)
            {
                if(s[i]==','||i==s.size()-1)
                {
                    if(i==s.size()-1)
                        tp+=s[i];
                    x[k][j]=tp;
                    j++;
                    tp.clear();
                    continue;
                }
                tp+=s[i];
            }
            /*for(int i=0;i<5;i++)
                cout<<x[k][i]<<endl;
            */
            k++;

        }
        if(berhoyejabe==1)
            break;
        int c1,c2,mi=999999,rs;
        for(int i=0; i<k; i++)
        {
            c1=0;
            for(int j=0; j<k; j++)
            {
                c2=0;
                if(j==i)
                    continue;
                for(int l=0; l<5; l++)
                {
                    for(int p=0; p<5; p++)
                    {
                        if(x[i][l]==x[j][p])
                            c2++;
                    }
                }
                c1+=5-c2;
            }
            if(c1<mi)
            {
                mi=c1;
                rs=i+1;
            }
        }
        cout<<rs<<endl;
    }
}
