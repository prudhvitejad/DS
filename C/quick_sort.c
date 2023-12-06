#include <stdio.h>

void QUICK_SORT(int [],int,int);
int PARTITION(int [],int,int);

int main()
{
	int arr[10];
	int n;
	printf("Enter The Length:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	printf("Before Sorting:");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	QUICK_SORT(arr,0,n-1);
	
	printf("After Sorting:");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void QUICK_SORT(int arr[],int first,int last)
{
	if(first<last)
	{
		int pivot_region = PARTITION(arr,first,last);
		QUICK_SORT(arr,first,pivot_region-1);
		QUICK_SORT(arr,pivot_region+1,last);
	}
}

int PARTITION(int arr[],int first,int last)
{
	int pivot = arr[last];
	int i = first-1; 				// to hold the element-index which is always <= pivot element 
	int j=first;					// for traversing the array from first to last-1 for checking every index is <= pivot element
	
	for(;j<=last-1;j++)
	{
		if(arr[j]<=pivot)			// swapping (i+1)-th index with j-th index
		{
			int temp = arr[i+1];
			arr[i+1] = arr[j];
			arr[j] = temp;
			i++;
		}
	}
	
	int temp = arr[i+1];			// swapping (i+1)-th index with last index
	arr[i+1] = arr[last];
	arr[last] = temp;
	
	return i+1;
}






