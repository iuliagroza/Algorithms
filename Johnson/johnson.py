# This code is contributed by Riyazul555

# Time Complexity  = O(V * E + V * (V + E) * log(V))  where where V is the number of vertices and E is the number of edges
# Space Complexity = O(V + E)                         where where V is the number of vertices and E is the number of edges

from queue import Queue
from heapq import heappush, heappop

nMax = 1005

def bf(nod, n, h, G):
    Q = Queue()
    in_queue = [False] * nMax
    nr = [0] * nMax
    for i in range(n):
        h[i] = 10**9
    h[nod] = 0
    Q.put(nod)
    in_queue[nod] = True
    while not Q.empty():
        nod = Q.get()
        in_queue[nod] = False
        for i in G[nod]:
            if h[nod] + i[1] < h[i[0]]:
                h[i[0]] = h[nod] + i[1]
                nr[i[0]] += 1
                if nr[i[0]] > n:
                    return True
                if not in_queue[i[0]]:
                    in_queue[i[0]] = True
                    Q.put(i[0])
    return False

def dijkstra(nod, n, d, G):
    Q = []
    in_queue = [False] * nMax
    heappush(Q, (0, nod))
    for i in range(n):
        if i != nod:
            d[i] = -10**9
            heappush(Q, (d[i], i))
    d[nod] = 0
    while Q:
        if not in_queue[Q[0][1]]:
            x = heappop(Q)[1]
            for i in G[x]:
                if d[x] - i[1] > d[i[0]]:
                    heappush(Q, (d[x] - i[1], i[0]))
                    d[i[0]] = d[x] - i[1]
            in_queue[x] = True
        else:
            heappop(Q)

def main():
    with open('input.txt') as fin, open('output.txt', 'w') as fout:
        n, m = map(int, fin.readline().split())
        G = [[] for _ in range(nMax)]
        for _ in range(m):
            x, y, w = map(int, fin.readline().split())
            G[x].append((y, w))
        s = n
        for i in range(n):
            G[s].append((i, 0))
        h = [0] * nMax
        ok = False
        if bf(s, n, h, G):
            fout.write('-1')
        else:
            for i in range(n):
                for j in range(len(G[i])):
                    G[i][j] = (G[i][j][0], G[i][j][1] + h[i] - h[G[i][j][0]])
                    fout.write(f'{i} {G[i][j][0]} {G[i][j][1]}\n')
            d = [0] * nMax
            for i in range(n):
                dijkstra(i, n, d, G)
                for j in range(n):
                    if i == j:
                        fout.write('0 ')
                    elif d[j] == -10**9:
                        fout.write('INF ')
                    else:
                        fout.write(f'{-d[j] - h[i] + h[j]} ')
                fout.write('\n')

if __name__ == '__main__':
    main()

