'''
-> The Heart of QuickSort is the Partition Algorithm

Partition Algorithm:
--------------------
-> Select a pivot element & place it in its position so that it is  sorted & we have to sort elements before it & after it except that because it is already sorted
-> And this process continuous

-> pivot region = All elements left to it should less than or equal to point & all the elements right to it should greater than this
-> i = to hold the element index which is always <= pivot element
-> j = for traversing array from first to last-1 for checking every index is <= pivot element
-> SWapping is done between (i+1) & j because both 'i' & 'j' are pointing to the elements less-than or equal to pivot
-> So we increment 'i' and swap it with 'j', so that 'i' will always be pointing to the element less than or equal to pivot

'''
def Partition(arr,first,last):
    pivot = arr[last]
    i = first-1 #to hold the element-index which is always <= pivot element
    j = first   #for traversing the array from first to last-1 for checking every index is <= pivot element

    while(j <= last-1):
        if(arr[j] <= pivot):    #swapping (i+1)-th index with j-th index
            temp = arr[i+1]
            arr[i+1] = arr[j]
            arr[j] = temp
            i += 1
        j +=1
    
    temp = arr[i+1]     #swapping (i+1)-th index with last index
    arr[i+1] = arr[j]
    arr[j] = temp
    
    return i+1


def QuickSort(arr,first,last):
    if(first < last):
        pivot_region = Partition(arr,first,last)
        QuickSort(arr,first,pivot_region-1)
        QuickSort(arr,pivot_region+1,last)


# Example usage:
arr = [4, 2, 8, 1, 5,7,0,67]
QuickSort(arr, 0, len(arr)-1)
print(arr)