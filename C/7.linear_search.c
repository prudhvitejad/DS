#include <stdio.h>
int main() {
	int arr[20],n,i,num,found=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&num);
	for(i=0;i<n;i++) 
	{
		if(arr[i]==num)
			found=1;
	}
	if(found==1)
		printf("The Number You have Entered is in the Array\n");
	else
		printf("The Number You have Entered is not in the Array\n");
	return 0;
}
