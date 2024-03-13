#This code is contributed by Riyazul555

# Time Complexity = O(N)  where N is number of elements in input array 
# Space Complexity = O(N) where N is number of elements in input array

def main():
    with open(sys.argv[1], 'r') as fin, open(sys.argv[2], 'w') as fout:
        n = int(fin.readline())
        cod = list(map(int, fin.readline().split()))
        deg = [0] * (n + 5)
        ptr = 0

        for i in range(n):
            deg[cod[i]] += 1

        while deg[ptr] != 0:
            ptr += 1

        leaf = ptr
        p = [-1] * (n + 5)

        for i in range(n):
            p[leaf] = cod[i]
            if deg[cod[i]] == 0 and cod[i] < ptr:
                leaf = cod[i]
            else:
                ptr += 1
                while deg[ptr] != 0:
                    ptr += 1
                leaf = ptr

        fout.write(str(n + 1) + "\n")
        fout.write(" ".join(map(str, p[:n+1])) + " ")

if __name__ == "__main__":
    import sys
    main()