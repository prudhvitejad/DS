#include <stdio.h>

int Binary_Search(int[],int l,int n,int key);

void main()
{
    int array[100],n,d,key,i;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    printf("\nEnter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    
    }
    printf("\nEnter the element to be search:");
    scanf("%d",&key);
    
    d = Binary_Search(array,0,n-1,key);
    
    if(d==-1)
        printf("\nElement is not present in the array");
    else
        printf("\nElement is present in the array");
}

int Binary_Search(int array[],int first,int last,int key)
{
    int mid;
    if(first<=last)
    {
        mid=(first+last)/2;
        if(array[mid]==key)
            return key;
        else if(array[mid]<key)
            Binary_Search(array,mid+1,last-1,key);
        else
            Binary_Search(array,0,mid-1,key);
    }        
    else
        return -1;
}





