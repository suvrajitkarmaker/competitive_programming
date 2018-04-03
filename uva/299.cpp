#include <bits/stdc++.h>
using namespace std;
int inser(int a[],int n)
{
    int key,j,c=0;
    for(int i=1; i<n; i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
            c++;
        }
        a[j+1]=key;
    }
    printf("Optimal train swapping takes %d swaps.\n",c);
}
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        scanf("%d",&n);
        int a[n];
        for(int j=0; j<n; j++)
        {
            scanf("%d",&a[j]);
        }
        inser(a,n);

    }
}
