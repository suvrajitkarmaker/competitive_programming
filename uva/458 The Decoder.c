#include <stdio.h>
#include <string.h>
int main()
{
    char a[1000000];
    int n,i;
    while(gets(a))
    {
        for(i=0;i<strlen(a);i++)
        {
            printf("%c",a[i]-7);
        }
        printf("\n");
    }
    return 0;
}
