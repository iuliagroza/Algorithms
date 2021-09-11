# This code is contributed by @iuliagroza

# Time Complexity: O(n)
# Space Complexity: O(n)

def Linear_Search(arr, elem):
    for i in range(len(arr)):
        if arr[i] == elem:
            return i
    return -1

a = [2, 56, 45, 13, 9, 0]
value1 = 13
value2 = 299

index1 = Linear_Search(a, value1)  # Searching an existent value in the list
print(index1)

index2 = Linear_Search(a, value2)  # Searching an inexistent value in the list
print(index2)