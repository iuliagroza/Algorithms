# This code is contributed by @iuliagroza

# Time Complexity: O(d * (n + b)), where d is the number of digits in the given list, n is the number of elements in the list, and b is the base or bucket size used
# Space Complexity: O(n + 2 ^ d)

def Counting_Sort(arr, exp1):
    n = len(arr)
    output = [0] * (n)
    count = [0] * (10)
    for i in range(0, n):
        index = (arr[i] / exp1)
        count[(index) % 10] += 1
    for i in range(1, 10):
        count[i] += count[i-1]
    i=n-1
    while i>=0:
        index = (arr[i]/exp1)
        output[count[(index)%10]-1] = arr[i]
        count[(index)%10] -= 1
        i-=1
    i=0
    for i in range(0, len(arr)):
        arr[i] = output[i]

def Radix_Sort(arr):
    max1 = max(arr)
    exp = 1
    while max1 / exp > 0:
        Counting_Sort(arr, exp)
        exp *= 10

a = [2, 56, 45, 13, 9, 0]

Radix_Sort(a)
print(a)