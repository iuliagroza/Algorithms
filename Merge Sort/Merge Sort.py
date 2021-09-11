# This code is contributed by @iuliagroza

# Time Complexity: O(n*log2(n))
# Additional Space: O(n)

def Merge_Sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]
        Merge_Sort(left)
        Merge_Sort(right)
        i = j = k = 0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1
        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1
        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1

a = [2, 56, 45, 13, 9, 0]

Merge_Sort(a)
print(a)