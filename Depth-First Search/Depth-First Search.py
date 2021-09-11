# This code is contributed by @iuliagroza

# Time Complexity: O(|V|+|E|), where |V| is the number of vertices and |E| the number of edges
# Space Complexity: O(|V|)

# Calculate the number of connected components using DFS in an undirected graph

n = 6
m = 3
edges = [[1, 2], [1, 4], [3, 5]]

G = {}  # Represent the graph as an adjacency list (dictionary)
for i in range(1, n+1):
    G.update({i: []})

for i in range(len(edges)):
    G[edges[i][0]].append(edges[i][1])
    G[edges[i][1]].append(edges[i][0])

def dfs(node, G, vis):
    vis[node] = 1;
    for i in range(len(G[node])):
        if vis[G[node][i]]==0:
            dfs(G[node][i], G, vis)  # Recursive call for node's neighbour

connected = 0  # Solution / number of connected components
vis = []
for i in range(1, n+2):
    vis.append(0)

for i in range(1, n+1):
    if vis[i]==0:
        connected += 1
        dfs(i, G, vis)

print(connected)