# This code is contributed by @iuliagroza

# Time Complexity: O(n^2)
# Space Complexity: O(n)

def Bubble_Sort(arr, n):
    for i in range(n-1):
        for j in range(n-i-1):
            if a[j] > a[j+1]:
                a[j], a[j+1] = a[j+1], a[j]

a = [2, 56, 45, 13, 9, 0]
n = len(a)

Bubble_Sort(a, n)
print(a)