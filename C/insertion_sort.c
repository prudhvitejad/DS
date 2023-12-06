#include <stdio.h>

void INSERTION_SORT(int [],int);

int main()
{
	int arr[10];
	int n;
	printf("Enter the Length of Array:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
		
	printf("Before Sorting:");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	
	INSERTION_SORT(arr,n-1);
	
	printf("After Sorting:");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]); 
	printf("\n");
}

void INSERTION_SORT(int arr[],int n)
{
	int item,i,j;
	for(i=1;i<n;i++)
	{
		item = arr[i];
		j = i-1;
		
		while( j>0 && item<arr[j] )
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		
		arr[j+1] = item;
	}
}





