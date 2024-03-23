# This code is contributed by Riyazul555


# Time Complexity = O(N log N), where N is the size of input
# Space Complexity = O(N),      where N is the size of input

import sys

nMax = 1000 
def dfs(nod, val, G, cod):
    if G[nod][0] == -1:
        cod[nod] = val
        return
    dfs(G[nod][0], val + "0", G, cod)
    dfs(G[nod][1], val + "1", G, cod)

def main(argv):
    fin = open(argv[1], 'r')
    fout = open(argv[2], 'w')
    n = int(fin.readline())
    fr = [0] * nMax
    val = [0] * nMax
    Q = []
    for i in range(n):
        ch = fin.read(1)
        fr[i] = int(fin.readline())
        val[i] = i
        Q.append(i)
    G = [[-1, -1] for _ in range(nMax)]
    z = n - 1
    while len(Q) > 1:
        x = Q.pop(0)
        y = Q.pop(0)
        z += 1
        fr[z] = fr[x] + fr[y]
        val[z] = min(val[x], val[y])
        Q.append(z)
        G[z][0] = x
        G[z][1] = y
    cod = ["" for _ in range(nMax)]
    dfs(z, "", G, cod)
    s1 = fin.readline().strip()
    s2 = ""
    v = []
    for i in range(len(s1)):
        s2 += s1[i]
        ok = False
        for j in range(len(v)):
            if s2 == cod[j]:
                fout.write(v[j])
                s2 = ""
                ok = True
                break
        if not ok:
            v.append(s2)
    fin.close()
    fout.close()

if __name__ == "__main__":
    main(sys.argv)
