# This code is contributed by Riyazul555

# Time Complexity  =  O(V + E)  
# Space Complexity =  O(V + E)  

import sys

def euler(nod, G, e, viz):
    while G[nod]:
        next_node, edge = G[nod].pop()  
        if not viz[edge]:
            viz[edge] = 1
            euler(next_node, G, e, viz)
    e.append(nod)

if __name__ == "__main__":
    input_file = sys.argv[1]
    output_file = sys.argv[2]

    with open(input_file, 'r') as fin, open(output_file, 'w') as fout:
        n, m = map(int, fin.readline().split())
        G = [[] for edge in range(n + 1)] 
        for _ in range(m):
            x, y = map(int, fin.readline().split())
            G[x].append((y, _ + 1))
            G[y].append((x, _ + 1))

        e = []
        viz = [0] * (m + 1) 
        euler(0, G, e, viz)

        for i in range(len(e) - 1, 0, -1):
            fout.write(str(e[i]) + ' ')
