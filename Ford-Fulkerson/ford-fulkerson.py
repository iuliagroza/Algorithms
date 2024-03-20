# This code was contributed by Riyazul555

# Time Complexity = O(M * (V + E))  
# Space Complexity = O(V^2)

from collections import deque
import sys

def bfs(G, n, dad, C):
    Q = deque()
    Q.append(1)
    while Q:
        nod = Q.popleft()
        for i in G[nod]:
            if not dad[i] and C[nod][i] > 0:
                dad[i] = nod
                Q.append(i)
    return dad[n]

def main(input_file, output_file):
    with open(input_file, 'r') as fin, open(output_file, 'w') as fout:
        n, m = map(int, fin.readline().split())
        G = [[] for _ in range(n + 5)]
        C = [[0] * (n + 5) for _ in range(n + 5)]

        for _ in range(m):
            x, y, c = map(int, fin.readline().split())
            x += 1
            y += 1
            C[x][y] = c
            G[x].append(y)
            G[y].append(x)

        flow = 0
        dad = [0] * (n + 5)
        while bfs(G, n, dad, C) != 0:
            for i in G[n]:
                Min = C[i][n]
                j = i
                while j != 1:
                    Min = min(Min, C[dad[j]][j])
                    j = dad[j]
                j = i
                while j != 1:
                    C[dad[j]][j] -= Min
                    C[j][dad[j]] += Min
                    j = dad[j]
                flow += Min
                C[i][n] -= Min
                C[n][i] += Min
            dad = [0] * (n + 5)
        fout.write(str(flow))

if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2])
