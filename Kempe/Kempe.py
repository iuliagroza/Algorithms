
# This code is contributed by Riyazul555


# Time Complexity = O(N^3) (approximate)
# Space Complexity = O(N)



from collections import deque

MOD = 1077563119
nMax = 25

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

def is_connected(n, m, G, vert):
    viz = [False] * nMax
    bfs(vert[0], G, viz)
    return all(viz[i] for i in vert)

def is_complete(n, G, vert):
    return all(len(G[i]) == n - 1 for i in vert)

def chromatic_polynomial(k, n, m, G, vert):
    if m == 0:
        p = 1
        for i in range(1, n + 1):
            p = (p % MOD * k % MOD) % MOD
        return p

    if is_complete(n, G, vert):
        p = 1
        for i in range(k - n + 1, k + 1):
            p = (p % MOD * i % MOD) % MOD
        return p

    if is_connected(n, m, G, vert) and m == n - 1:
        p = k % MOD
        for i in range(1, n):
            p = (p % MOD * (k - 1) % MOD) % MOD
        return p

    G1 = [[] for _ in range(nMax)]
    ind = 0
    while not G[vert[ind]]:
        ind += 1
    p1 = vert[ind]
    p2 = G[p1][-1]
    for i in vert:
        for j in G[i]:
            if (i == p1 and j == p2) or (i == p2 and j == p1):
                continue
            G1[i].append(j)
    vert2 = [i for i in vert if i != p2]
    G2 = [[] for _ in range(nMax)]
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
    return (chromatic_polynomial(k, n, m - 1, G1, vert) % MOD - chromatic_polynomial(k, n - 1, sz, G2, vert2) % MOD + MOD) % MOD

def chromatic_number(n, m, G, vert):
    for i in range(1, n + 1):
        if chromatic_polynomial(i, n, m, G, vert):
            return i

def kempe_algorithm(n, m, G):
    vert = list(range(n))
    k = chromatic_number(n, m, G, vert)

    st_sz = 0
    st = [0] * nMax
    gr = [0] * nMax

    for i in range(n):
        gr[i] = len(G[i])

    while st_sz < n:
        cnt = 0
        for i in range(n):
            if gr[i] > -1 and gr[i] < k:
                gr[i] = -1
                st[st_sz] = i
                st_sz += 1
                for j in G[i]:
                    gr[j] -= 1
                cnt += 1

        if cnt == 0:
            pos = 0
            while gr[pos] == -1 and pos < n - 1:
                pos += 1
            gr[pos] = -1
            st[st_sz] = pos
            st_sz += 1
            for j in G[pos]:
                gr[j] -= 1

    col = [-1] * nMax

    for i in range(st_sz - 1, -1, -1):
        ap = [False] * k
        for j in G[st[i]]:
            if col[j] != -1:
                ap[col[j]] = True
        ncol = 0
        while ap[ncol] and ncol < k:
            ncol += 1
        if ncol < k:
            col[st[i]] = ncol

    return k, col

def main():
    with open("pc.in", "r") as fin, open("pc.out", "w") as fout:
        n, m = map(int, fin.readline().split())
        G = [[] for _ in range(nMax)]
        for _ in range(m):
            x, y = map(int, fin.readline().split())
            G[x].append(y)
            G[y].append(x)
        vert = list(range(n))
        k, col = kempe_algorithm(n, m, G)
        fout.write(f"{k}\n")
        fout.write(" ".join(map(str, col[:n])))

if __name__ == "__main__":
    main()
