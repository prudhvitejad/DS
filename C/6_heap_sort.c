#include<stdio.h>
int size;

void heapsort(int *,int);
void max_heapify(int * ,int ,int );
void build_max_heap(int * ,int );

int main()
{
	int n,i,j,k;
	printf("\nEnter the no of elements:\n");
	scanf("%d",&n);
	size=n;
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	heapsort(arr,n);
	printf("\nSorted elemnts...\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}

void heapsort(int *arr,int n)
{
	build_max_heap(arr,n);
	printf("\n");
	while(n>=1)
	{
		
		int temp=arr[0];
		arr[0]=arr[n-1];
		arr[n-1]=temp;
		--n;
		max_heapify(arr,0,n);
	}
}

void build_max_heap(int *arr ,int n)
{
	int k=(n/2)-1;
	for(int i=k;i>=0;i--)
		max_heapify(arr,i,n);
}

void max_heapify(int *arr,int i,int n)
{
	int largest=i,l=2*i+1,r=2*i+2;
	if(l<n && arr[l]>arr[i])
		largest=l;
	if(r<n && arr[r]>arr[largest])
		largest=r;
	if(largest!=i)
	{
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		max_heapify(arr,largest,n);
	}
}





