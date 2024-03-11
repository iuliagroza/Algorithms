
# This code is contributed by Riyazul555


# Time Complexity = O(2^N), where N is the number of vertices
# Space Complexity = O(N + M), where M is the number of edges

from functools import reduce
from collections import deque

MOD = 1077563119

def bfs(nod, G, viz):
    Q = deque()
    viz[nod] = True
    Q.append(nod)
    while Q:
        nod = Q.popleft()
        for i in G[nod]:
            if not viz[i]:
                viz[i] = True
                Q.append(i)

def is_connected(G, vert):
    viz = [False] * len(G)
    bfs(vert[0], G, viz)
    return all(viz[i] for i in vert)

def is_complete(G, vert):
    return all(len(G[i]) == len(vert) - 1 for i in vert)

def chromatic_polynomial(k, n, m, G, vert):
    if m == 0:
        return pow(k, n, MOD)

    if is_complete(G, vert):
        return reduce(lambda x, y: (x * y) % MOD, range(k - n + 1, k + 1), 1)

    if is_connected(G, vert) and m == n - 1:
        return reduce(lambda x, y: (x * (k - 1)) % MOD, range(1, n), k)

    G1 = [[] for _ in range(len(G))]
    ind = next(i for i, val in enumerate(vert) if G[val])
    p1 = vert[ind]
    p2 = G[p1][-1]
    for i in vert:
        for j in G[i]:
            if (i == p1 and j == p2) or (i == p2 and j == p1):
                continue
            G1[i].append(j)
    vert2 = [i for i in vert if i != p2]
    G2 = [[] for _ in range(len(G))]
    for i in vert2:
        for j in G1[i]:
            if j == p2:
                if p1 not in G2[i]:
                    G2[i].append(p1)
            else:
                if j not in G2[i]:
                    G2[i].append(j)
        if i == p1:
            for j in G1[p2]:
                if j not in G2[i]:
                    G2[i].append(j)
    sz = sum(len(G2[i]) for i in vert2) // 2
    return (chromatic_polynomial(k, n, m - 1, G1, vert) - chromatic_polynomial(k, n - 1, sz, G2, vert2) + MOD) % MOD

def chromatic_number(n, m, G, vert):
    for i in range(1, n + 1):
        if chromatic_polynomial(i, n, m, G, vert):
            return i

def kempe_algorithm(n, m, G):
    vert = list(range(n))
    k = chromatic_number(n, m, G, vert)

    st = []
    gr = [0] * len(G)

    for i in range(n):
        gr[i] = len(G[i])

    while len(st) < n:
        cnt = 0
        for i in range(n):
            if gr[i] > -1 and gr[i] < k:
                gr[i] = -1
                st.append(i)
                for j in G[i]:
                    gr[j] -= 1
                cnt += 1

        if cnt == 0:
            pos = next((i for i, val in enumerate(gr) if val != -1), None)
            gr[pos] = -1
            st.append(pos)
            for j in G[pos]:
                gr[j] -= 1

    col = [-1] * len(G)

    for i in range(len(st) - 1, -1, -1):
        ap = [False] * k
        for j in G[st[i]]:
            if col[j] != -1:
                ap[col[j]] = True
        ncol = next(i for i, val in enumerate(ap) if not val)
        col[st[i]] = ncol

    return k, col

def main():
    with open("pc.in", "r") as fin, open("pc.out", "w") as fout:
        n, m = map(int, fin.readline().split())
        G = [[] for _ in range(n)]
        for _ in range(m):
            x, y = map(int, fin.readline().split())
            G[x].append(y)
            G[y].append(x)
        k, col = kempe_algorithm(n, m, G)
        fout.write(f"{k}\n")
        fout.write(" ".join(map(str, col[:n])))

if __name__ == "__main__":
    main()
