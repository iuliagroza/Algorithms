# This code is contributed by @iuliagroza

# Time Complexity: O(n*m), where n is the length of the A sequence and m the length of the B sequence.
# Additional Space: O(n*m)

n = 5
A = [1, 7, 3, 9, 8]

m = 3
B = [7, 5, 8]

lcs = []
for i in range(0, n+1):
    lcs.append([]);
    for j in range(0, m+1):
        lcs[i].append(0)

for i in range(1, n+1):  # Building the DP structure using the recurrence
    for j in range(1, m+1):
        if A[i-1]==B[j-1]:
            lcs[i][j] = lcs[i-1][j-1]+1;
        else:
            lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1])

i=n
j=m
sol = []
while i>0 and j>0:  # Build the solution array starting from the maximum (in reversed order)
    if A[i-1]==B[j-1]:
        sol.append(A[i-1])
        i -= 1
        j -= 1
    elif lcs[i-1][j] < lcs[i][j-1]:
        j -= 1
    else:
        i -= 1

print(len(sol))
sol = sol[::-1]  # Reverse the solution array to print it in ascending order
print(sol)