# This code is contibuted by Riyazul555

# Time complexity = O(N * (N + M))  N represents number of vertices
# Space complexity = O(N + M)       M represnts number of  edges


def graph_coloring():
    n_max = 25
    fin = open("pc.in", "r")
    fout = open("pc.out", "w")

    n, m = map(int, fin.readline().split())
    G = [[] for _ in range(n_max)]

    for _ in range(1, m + 1):
        x, y = map(int, fin.readline().split())
        G[x].append(y)
        G[y].append(x)

    vert = list(range(n))
    more_colors = True
    solk = 0
    colk = [0] * n_max

    for k in range(1, n + 1):
        st_sz = 0
        st = [0] * n_max
        gr = [0] * n_max

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

        col = [-1] * n_max

        for i in range(st_sz - 1, -1, -1):
            ap = [False] * k
            for j in G[st[i]]:
                if col[j] >= 0:
                    ap[col[j]] = True
            ncol = 0
            while ap[ncol] and ncol < k:
                ncol += 1

            if ncol < k:
                col[st[i]] = ncol
            else:
                col[st[i]] = -2

        ok = True
        Max = -1

        for i in range(n):
            if col[i] < 0:
                ok = False
            Max = max(Max, col[i])

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
