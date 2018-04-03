#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int main()
{
    char a[1000],b[5]="one",c[5]="two";
    int n,i,j,k,l;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%s",a);
        l=strlen(a);
        int c1=0,c2=0;
        if(l==3)
        {
            for(j=0; j<3; j++)
            {
                if(a[j]==b[j])
                    c1++;
                if(a[j]==c[j])
                    c2++;
            }
            if(c1>c2)
                printf("1\n");
            else
                printf("2\n");
        }
        else if(l==5)
            printf("3\n");
    }
    return 0;
}
