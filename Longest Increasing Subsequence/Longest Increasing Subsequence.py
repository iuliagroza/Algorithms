# This code is contributed by @iuliagroza

# Time Complexity: O(n*log n) (efficient)
# Additional Space: O(n)

# The following sources solve the Longest STRICTLY Increasing Subsequence problem

def output(k, ind, A, sol):  # Function that builds the solution array recursively from end to beginning
    if(k>0):
        output(ind[k], ind, A, sol)
        sol.append(A[k])

def src(x, k, A, last_pos):  # Binary Search function that searches for the maximum value element after our current element, bigger than it
    sol=0
    left=1
    right=k
    while left <= right:
        mid = (left+right)//2
        if x > A[last_pos[mid]]:
            left = mid+1
            sol = max(sol, mid)
        else:
            right = mid-1
    return sol

n = 5
A = [24, 12, 15, 15, 19]
for i in range(5):
    A.append(0)

last_pos = []
for i in range(n+2):
    last_pos.append(0)
last_pos[1] = 1

best = []
for i in range(n+2):
    best.append(0)
best[1] = 1

ind = []
for i in range(n+2):
    ind.append(0)

k=1
for i in range(2, n+1):  # Rrecurrence Implementation
    pos = src(A[i], k, A, last_pos)
    ind[i] = last_pos[pos]
    best[i] = pos+1
    last_pos[pos+1] = i
    k = max(k, best[i])

lst=0
Max=0
for i in range(1, n+1):  # Finding the maximum length
    if best[i]>Max:
        Max = best[i]
        lst = i

print(Max)  # Printing the solution
sol = []
output(lst, ind, A, sol)
print(sol)