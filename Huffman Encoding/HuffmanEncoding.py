#This code was contributed by Riyazul555

#Time Complexity = O(N log N)    where N is the number of unique characters
#Space Complexity = O(N)         where N is the number of unique characters

from queue import PriorityQueue

def dfs(nod, val, G, cod):
    if G[nod][0] == -1:
        cod[nod] = val
        return
    dfs(G[nod][0], val + "0", G, cod)
    dfs(G[nod][1], val + "1", G, cod)

def main(input_file, output_file):
    with open(input_file, 'r') as fin, open(output_file, 'w') as fout:
        ap = {}
        s = fin.readline().rstrip()
        v = sorted(set(s))
        fr = [0] * len(v)
        val = [0] * len(v)
        for ch in s:
            ap[ch] = ap.get(ch, 0) + 1

        fout.write(str(len(v)) + "\n")
        for i in range(len(v)):
            fout.write(v[i] + " " + str(ap[v[i]]) + "\n")
            fr[i] = ap[v[i]]
            val[i] = i

        def compare(a, b):
            return fr[a] > fr[b] or (fr[a] == fr[b] and val[a] > val[b])

        Q = PriorityQueue()
        for i in range(len(v)):
            Q.put(i)

        G = [[-1] * 2 for _ in range(len(v))]
        z = len(v) - 1
        while Q.qsize() > 1:
            x = Q.get()
            y = Q.get()
            z += 1
            fr[z] = fr[x] + fr[y]
            val[z] = min(val[x], val[y])
            Q.put(z)
            G[z][0] = x
            G[z][1] = y

        cod = [""] * len(v)
        dfs(z, "", G, cod)
        codif = {v[i]: cod[i] for i in range(len(v))}
        for ch in s:
            fout.write(codif[ch])

if __name__ == "__main__":
    main("input.txt", "output.txt")  # Change input and output file names accordingly
