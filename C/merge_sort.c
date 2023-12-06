#include <stdio.h>

void MERGE(int [],int,int,int);
void MERGE_SORT(int [],int,int);

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
	
	MERGE_SORT(arr,0,n-1);
	
	printf("After Sorting:");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]); 
	printf("\n");
}

void MERGE_SORT(int arr[],int first,int last)
{
	if(first < last)
	{
		int mid = (first+last)/2;
		
		MERGE_SORT(arr,first,mid);
		MERGE_SORT(arr,mid+1,last);
		MERGE(arr,first,mid,last);
	}
} 

void MERGE(int arr[],int first,int mid,int last)
{
	int n1 = mid-first+1;
	int n2 = last-mid;
	int L[n1];
	int R[n2];
	
	int first_index = 0;
	int second_index = 0;
	int index = first;
	
	for(index=first;index<=mid;index++)
	{
		L[first_index] = arr[index];
		first_index++;
	}
	
	for(index=mid+1;index<=last;index++)
	{
		R[second_index] = arr[index];
		second_index++;
	}
	
	first_index = 0, second_index = 0, index = first;
	
	while(first_index<n1 && second_index<n2)
	{
		if(L[first_index]<=R[second_index])
		{
			arr[index] = L[first_index];
			index++;
			first_index++;
		}	
		else
		{
			arr[index] = R[second_index];
			index++;
			second_index++;
		} 
	}
	
	while(second_index<n2)
	{
		arr[index] = R[second_index];
		index++;
		second_index++;
	}
	
	while(first_index<n1)
	{
		arr[index] = L[first_index];
		index++;
		first_index++;
	} 
}






