#include <stdio.h>
int main() {
	int arr[20],n,i,j,temp,minIndex,min;
	scanf("%d",&n);
	for(i=0;i<n;i++) 
		scanf("%d",&arr[i]);
	
	for(i=0;i<n;i++) 
	{
		minIndex=i;
		min=arr[minIndex];
		for(j=i+1;j<n;j++) 
		{
			if(arr[j]<min) 
			{
				min=arr[j];
				minIndex=j;
			}	
		}
		arr[minIndex]=arr[i];
		arr[i]=min;
	}
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}
