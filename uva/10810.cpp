
#include <stdio.h>
long long int count=0;
void marge(int *l,int *r,int nl,int nr,int *a)
{
    int i=0,j=0,k=0;
    while(i<nl&&j<nr)
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
            count+=nl-i;
	
        }
    }
    while(i<nl)
    {
        a[k]=l[i];
        k++;
        i++;
    }
    while(j<nr)
    {
        a[k]=r[j];
        k++;
        j++;
    }
}
void margesort(int *a,int n)
{
    if(n<2)
        return;
    int mid=n/2;
    int left[mid],right[n-mid];
    for(int i=0;i<mid;i++)
        left[i]=a[i];
    for(int i=mid;i<n;i++)
    {
        right[i-mid]=a[i];
    }
    margesort(left,mid);
    margesort(right,n-mid);
    marge(left,right,mid,n-mid,a);
}
int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
         int a[n];
         count=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        margesort(a,n);
        printf("%lld\n",count);
    }
   
}
