# This code is contributed by @MahmoudFettal

# Time Complexity: O(n^2)
# Space Complexity: O(1)

# The Insertion Sort
def insertion(L):
    n = len(L)
    for i in range(1,n):
        j = i
        value = L[i]
        while j >= 0:
            if L[j] < value:
                break
            j -= 1
        pos = j + 1
        for k in range(i,pos,-1):
            L[k] = L[k-1]
        L[pos] = value
    return L

# It is not exactly the insertion but instead of taking a position and then acting while searching for the position we move value
def insertionXbubble(L):
    n = len(L)
    for i in range(1,n):
        while i > 0:
            if L[i-1] > L[i]:
                L[i-1],L[i] = L[i],L[i-1]
            else:
                break
            i -= 1
    return L

# Test
L = [1,5,3,9,0,6,2]
print(insertion(L))