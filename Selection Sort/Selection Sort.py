# This code is contributed by @iuliagroza

# Time Complexity: O(n ^ 2)
# Additional Space: O(1)

def selectionSort(a):
    # Traverse through all array elements
    for i in range(len(a)):
        # Find the minimum element in remaining unsorted array
        min_index = i
        for j in range(i + 1, len(a)):
            if a[min_index] > a[j]:
                min_index = j

        # Swap the found minimum element with the first element
        a[i], a[min_index] = a[min_index], a[i]

    for i in range(len(a)):
        print("%d" % a[i]),

a = [64, 25, 12, 22, 11]
selectionSort(a)