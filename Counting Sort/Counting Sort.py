# This code is contributed by @iuliagroza

# Time Complexity: O(Max-Min), where Max and Min are the maximum, respectively the minimum value of the array
# Additional Space: O(Max)

def Counting_Sort(arr, n):
    fr = {}
    Min = arr[0]
    Max = arr[0]
    for i in range(n):
        fr.update({arr[i]: 0})
        Min = min(Min, arr[i])
        Max = max(Max, arr[i])
    for i in range(n):
        fr[arr[i]] += 1;
    arr = []
    for i in range(Min, Max+1):
        if i in fr:
            if fr[i]!=0:
                for j in range(fr[i]):
                    arr.append(i)
    print(arr)


a = [2, 56, 45, 13, 9, 0]
n = len(a)

Counting_Sort(a, n)