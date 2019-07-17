#include <stdio.h>
#include <iostream>
using namespace std;
void merge(int *l,int *r,int ln,int rn,int *a)
{
    int i=0,j=0,k=0;
    while(i<ln && j<rn)
    {
        if(l[i]<=r[j])
        {
            a[k]=l[i];
            i++;
            k++;
        }
        else
        {
            a[k]=r[j];
            j++;
            k++;
        }
        
    }
    while (i<ln)
    {
        /* code */
        a[k]=l[i];
        i++;
        k++;
    }
    while (j<rn)
    {
        /* code */
        a[k]=r[j];
        j++;
        k++;
    }
}
void mergesort(int *a,int n)
{
    if(n<2)
        return;
    int i,mid=n/2;

    int left[mid],right[n-mid];
    for(int i=0;i<mid;i++)
        left[i]=a[i];
    for(int i=mid;i<n;i++)
        right[i-mid]=a[i];
    mergesort(left,mid);
    mergesort(right,n-mid);
    merge(left,right,mid,n-mid,a);
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
    

    mergesort(a,n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("%d ",a[i]);
    }
    printf("\n");


}
