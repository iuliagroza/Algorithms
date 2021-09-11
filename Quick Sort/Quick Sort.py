# This code is contributed by @iuliagroza

# Time Complexity: O(n*log2(n))
# Space Complexity: O(n) (no additional space)

# Implementation with median as a pivot

def Quick_Sort(arr, left, right):
    i=left
    j=right
    mid=int((left+right)/2)
    piv = arr[mid]
    while i<=j:
        while arr[i] < piv:
            i += 1
        while arr[j] > piv:
            j -= 1
        if i<=j:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1
    if i<right:
        Quick_Sort(arr, i, right)
    if j>left:
        Quick_Sort(arr, left, j)

# 2 56 45 13 9 0
a = [2, 56, 45, 13, 9, 0]
n = len(a)

Quick_Sort(a, 0, n-1)
print(a)