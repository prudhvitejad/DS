#The key operation of the MergeSort algorithm is the merging of 2 sorted sequences in the "combine" step
def merge(arr, first, mid, last):
    left = arr[first:mid+1]
    right = arr[mid+1:last+1]
    
    first_index = second_index = 0
    index = first
    
    while first_index < len(left) and second_index < len(right):
        if left[first_index] <= right[second_index]:
            arr[index] = left[first_index]
            first_index += 1
        else:
            arr[index] = right[second_index]
            second_index += 1
        index += 1
    
    while first_index < len(left):
        arr[index] = left[first_index]
        first_index += 1
        index += 1
    
    while second_index < len(right):
        arr[index] = right[second_index]
        second_index += 1
        index += 1


def mergeSort(arr, first, last):
    if first < last:
        mid = (first + last) // 2
        mergeSort(arr, first, mid)
        mergeSort(arr, mid+1, last)
        merge(arr, first, mid, last)


# Example usage:
arr = [4, 2, 8, 1, 5]
mergeSort(arr, 0, len(arr)-1)
print(arr)
