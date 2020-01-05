#include<bits/stdc++.h>
using namespace std;
int arr[] = { 12, 11, 13, 5, 6, 7 };
void heapify(int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(n, largest);
	}
}

void heapSort(int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(i, 0);
	}
}
int main()
{

	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
	heapSort(n);
	for (int i = 0; i<n; ++i)
		printf("%d ",arr[i]);
    printf("\n");
}
