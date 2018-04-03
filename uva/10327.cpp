#include <bits/stdc++.h>
using namespace std;
int insertion(int a[],int n)
{
    int key,j,c=0;
    for(int i=1; i<n; i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            c++;
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    printf("Minimum exchange operations : %d\n",c);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[n];
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        insertion(a,n);
    }
}
