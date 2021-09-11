# This code is contributed by @iuliagroza

# Time Complexity: O(n) (for the Sum of n Elements problem)
# Space Complexity: O(n)

# Sum of n elements using DAC

def DAC(arr, start, finish):
    if start == finish:
        return arr[start]
    else:
        mid = int((start+finish)/2)
        sum1 = DAC(arr, start, mid)
        sum2 = DAC(arr, mid+1, finish)
        return sum1+sum2

a = [2, 56, 45, 13, 9, 0]
n = len(a)-1

sum = DAC(a, 0, n)
print(sum)