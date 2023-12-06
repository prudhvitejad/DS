#include <stdio.h>
int main() {
	int arr[20],n,i,j,temp;
	scanf("%d",&n);
	
	for(i=0;i<n;i++) 
		scanf("%d",&arr[i]);
	
	printf("The Array Before Sorting:");
	
	for(i=0;i<n;i++) 
		printf("%d ",arr[i]);

	for(i=0;i<n;i++) {
		for(j=0;j<n-i-1;j++) {
			if(arr[j]>arr[j+1]) {
				temp =arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	printf("\n");
	printf("The Array After Sorting:");
	
	for(i=0;i<n;i++) 
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
