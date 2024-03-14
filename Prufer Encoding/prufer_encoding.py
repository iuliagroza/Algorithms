# This code is contributed by Riyazul555

# Time Complexity  = O(N)  N is number of nodes in the tree
# Space Complexity = O(N)  N is number of nodes in the tree

def main():
    with open(sys.argv[1], 'r') as fin, open(sys.argv[2], 'w') as fout:
        n = int(fin.readline().strip())
        max_size = 100005  

        daddy = [0] * max_size
        deg = [0] * max_size

        for i in range(n):
            daddy[i] = int(fin.readline().strip())
            deg[i] += 1
            deg[daddy[i]] += 1

        ptr = -1
        for i in range(n):
            if deg[i] == 1 and ptr == -1:
                ptr = i

        sol = []
        leaf = ptr
        for i in range(n - 1):
            nxt = daddy[leaf]
            sol.append(nxt)
            deg[nxt] -= 1
            if deg[nxt] == 1 and nxt < ptr:
                leaf = nxt
            else:
                ptr += 1
                while deg[ptr] != 1:
                    ptr += 1
                leaf = ptr

        fout.write(str(n - 1) + "\n")
        fout.write(' '.join(map(str, sol)))

if __name__ == "__main__":
    import sys
    main()
