#BubbleSort works by repeatedly swapping adjacent elements that are out of order
def BubbleSort(arr):
    count = 0
    for i in range(0,len(arr)):
        for j in range(0,len(arr)-i-1):
            if(arr[j] > arr[j+1]):
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
                count +=1

        if(count == 0):
            break

# Example usage:
arr = [4, 2, 8, 1, 5,7,0,67]
BubbleSort(arr)
print(arr) 