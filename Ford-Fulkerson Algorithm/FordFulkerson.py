# This code is contributed by Riyazul555

# Time Complexity: O(V * E^2)  where V is the number of vertices and E is the number of edges.
# Space Complexity: O(V^2)     where V is the number of vertices.


from collections import deque

def bfs(G, C, n, dad):
    Q = deque()
    Q.append(1)
    while Q:
        nod = Q.popleft()
        for i in G[nod]:
            if not dad[i] and C[nod][i] > 0:
                dad[i] = nod
                Q.append(i)
    return dad[n]

if __name__ == "__main__":
    with open(sys.argv[1], 'r') as fin, open(sys.argv[2], 'w') as fout:
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
        while bfs(G, C, n, dad):
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

                    flow += Min
                    C[i][n] -= Min
                    C[n][i] += Min
                    j = dad[j]
            dad = [0] * (n + 5)
        fout.write(str(flow))
