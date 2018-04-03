#include <bits/stdc++.h>
using namespace std;
char s[1000000];
int main()
{
    char c;
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%s",s);
        int d=strlen(s),t;
        printf("Case %d: ",i+1);
        for(int k=0; k<d; k++)
        {
            if(s[k]>='A'&&s[k]<='Z')
            {
                t=0;
                c=s[k];
                k++;
                while(s[k]>='0'&&s[k]<='9')
                {
                    t=(t*10)+(s[k]-48);
                    k++;
                }
                k--;
                for(int j=0; j<t; j++)
                    printf("%c",c);
            }

        }
        printf("\n");
    }
}
