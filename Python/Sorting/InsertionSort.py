'''
-> We start with an empty left hand and the cards face down on the table
-> We then remove one card at a time from the table and insert it into the correct position in the left hand
-> To find the correct position for a card, we compare it with each of the cards already in the hand, from right to left
-> At all the times, the cards held in the left hand are sorted
'''
def InsertionSort(arr):
    for i in range(1,len(arr)):
        temp = arr[i]
        j = i-1

        #insert arr[i] into the sorted sequence of arr(1 to i-1)
        while((temp < arr[j]) and (j >= 0)):
            arr[j+1] = arr[j]
            j = j - 1
        
        arr[j+1] = temp


# Example usage:
arr = [4, 2, 8, 1, 5,7,0,67]
InsertionSort(arr)
print(arr) 