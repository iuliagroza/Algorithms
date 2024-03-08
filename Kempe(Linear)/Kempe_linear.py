# This code is contributed by Riyazul555

# Time complexity = O(N*(N + M))  N represents the number of vertices
# Space complexity = O(N + M)     M represents the number of edges

def graph_coloring():
    fin = open("pc.in", "r")
    fout = open("pc.out", "w")

    n, m = map(int, fin.readline().split())
    G = [[] for _ in range(n)]

    for _ in range(1, m + 1):
        x, y = map(int, fin.readline().split())
        G[x].append(y)
        G[y].append(x)

    more_colors = True
    solk = 0
    colk = [0] * n

    for k in range(1, n + 1):
        st = [0] * n
        gr = [len(G[i]) for i in range(n)]

        while st[0] < n:
            cnt = 0
            for i in range(n):
                if gr[i] > -1 and gr[i] < k:
                    gr[i] = -1
                    st[st[0]] = i
                    st[0] += 1
                    for j in G[i]:
                        gr[j] -= 1
                    cnt += 1

            if cnt == 0:
                try:
                    pos = next(i for i in range(n) if gr[i] != -1)
                    gr[pos] = -1
                    st[st[0]] = pos
                    st[0] += 1
                    for j in G[pos]:
                        gr[j] -= 1
                except StopIteration:
                    break

        col = [-1] * n

        for i in range(st[0] - 1, -1, -1):
            ap = [False] * k
            for j in G[st[i]]:
                if col[j] >= 0:
                    ap[col[j]] = True
            ncol = next(ncol for ncol in range(k) if not ap[ncol])

            if ncol < k:
                col[st[i]] = ncol
            else:
                col[st[i]] = -2

        ok = all(col[i] >= 0 for i in range(n))
        Max = max(col)

        if ok:
            solk = Max + 1
            colk[:n] = col[:n]
            more_colors = False

    fout.write(str(solk) + '\n')
    fout.write(' '.join(map(str, colk[:n])) + ' ')

    fin.close()
    fout.close()

if __name__ == "__main__":
    graph_coloring()
