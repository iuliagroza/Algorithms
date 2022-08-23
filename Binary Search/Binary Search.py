# This code is contributed by @iuliagroza

# Time complexity: O(log n)

def Binary_Search(arr, elem, left, right):
    if right > left:
        middle = (left+right)//2
        if arr[middle] == elem:
            return middle
        elif arr[middle] > elem:
            return Binary_Search(arr, elem, left, middle)  # Search in the left half
        else:
            return Binary_Search(arr, elem, middle+1, right)  # Search in the right half
    else:
        return -1  # Element not found


#to use binary search the list must be sorted and here the list is not sorted
a = [2, 56, 45, 13, 9, 0]
a = sorted(a)
n = len(a)
value1 = 13  # Existent value
value2 = 299 # Inexistent value

index1 = Binary_Search(a, value1, 0, n)
print(index1)

index2 = Binary_Search(a, value2, 0, n)
print(index2)