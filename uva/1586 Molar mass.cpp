#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j;
    char c[100];
    cin>>n;
    for(j=0; j<n; j++)
    {
        scanf("%s",c);
        double sum=0.0;
        for(i=0; i<strlen(c); i++)
        {
            if(i==strlen(c)-1)
            {
                if(c[i]>='0'&&c[i]<='9');
                else if(c[i]>='A'&&c[i]<='Z')
                {
                    if(c[i]=='C')
                        sum=sum+12.01;
                    else if(c[i]=='H')
                        sum=sum+1.008;
                    else if(c[i]=='O')
                        sum=sum+16.00;
                    else if(c[i]=='N')
                        sum=sum+14.01;
                }
            }
            else
            {
                if((c[i]>='A'&&c[i]<='Z')&&(c[i+1]>='0'&&c[i+1]<='9')&&(c[i+2]>='0'&&c[i+2]<='9'))
                {
                    double a=c[i+1]-48;
                    double b=c[i+2]-48;
                    double x=(a*10.0)+b;
                    if(c[i]=='C')
                        sum=sum+(x*12.01);
                    else if(c[i]=='H')
                        sum=sum+(x*1.008);
                    else if(c[i]=='O')
                        sum=sum+(x*16.00);
                    else if(c[i]=='N')
                        sum=sum+(x*14.01);
                    i=i+2;
                }
                else if((c[i]>='A'&&c[i]<='Z')&&(c[i+1]>='0'&&c[i+1]<='9'))
                {
                    double x=c[i+1]-48;
                    if(c[i]=='C')
                        sum=sum+(x*12.01);
                    else if(c[i]=='H')
                        sum=sum+(x*1.008);
                    else if(c[i]=='O')
                        sum=sum+(x*16.00);
                    else if(c[i]=='N')
                        sum=sum+(x*14.01);
                    i++;
                }
                else if((c[i]>='A'&&c[i]<='Z')&&(c[i+1]>='A'&&c[i+1]<='Z'))
                {
                    if(c[i]=='C')
                        sum=sum+12.01;
                    else if(c[i]=='H')
                        sum=sum+1.008;
                    else if(c[i]=='O')
                        sum=sum+16.00;
                    else if(c[i]=='N')
                        sum=sum+14.01;
                }
            }
        }
        printf("%0.3lf\n",sum);
    }
}
