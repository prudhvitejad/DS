#include <stdio.h>
int main() {
	int arr[20],n,i,num,found=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&num);
	int mid,beg,end;
	beg=0;
	end=n-1;
	
	while(beg<=end) {
		mid=(beg+end)/2;
		if(arr[mid]==num) {
			printf("%d is present in the array at position = %d\n",num,mid);
			found=1;
			break;
		}
		if(arr[mid]>num)
			end=mid-1;
		else if(arr[mid]<num)
			beg=mid+1;
	}
	
	
	
	if(beg>end && found==0)
		printf("The Number You have Entered is not in the Array\n");
	return 0;
}
