#include <stdio.h>
#include <iostream>
using namespace std;
void insertionsort(int *a,int n)
{
    int j,key;
    for (int i = 1; i < n; i++)
    {
        /* code */
        key=a[i];
        j=i-1;
        while (j>=0 && a[j]>key)
        {
            /* code */
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    

    insertionsort(a,n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("%d ",a[i]);
    }
    printf("\n");


}
