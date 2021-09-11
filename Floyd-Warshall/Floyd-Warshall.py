# This code is contributed by @iuliagroza

# Time Complexity: O(|V|^3), where |V| is the number of vertices
# Space Complexity: O(|V|^2)

def Floyd_Warshall(n, mat):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if i!=j and mat[i][k] and mat[k][j] and (mat[i][j]==0 or mat[i][j] > mat[i][k]+mat[k][j]):
                    mat[i][j] = mat[i][k] + mat[k][j]


n = 5
mat = [[0, 3, 9, 8, 3], [5, 0, 1, 4, 2], [6, 6, 0, 4, 5], [2, 9, 2, 0, 7], [7, 9, 3, 2, 0]]

Floyd_Warshall(n, mat)

print(mat)