# This code is contributed by @iuliagroza

# Time Complexity: O(|V|+|E|), where |V| is the number of vertices and |E| the number of edges
# Space Complexity: O(|V|)

# Shortest path (minimum number of edges) between a source node and all the others using BFS in a directed graph

n = 5
m = 7
s = 2
edges = [[1, 2], [2, 1], [2, 2], [3, 2], [2, 5], [5, 3], [4, 5]]

G = {}  # Represent the graph as a list of adjacency (dictionary)
for i in range(1, n+1):
    G.update({i: []})

for i in range(len(edges)):
    G[edges[i][0]].append(edges[i][1])

dist = []  # The solution list
vis = []
for i in range(1, n + 2):
    dist.append(0)
    vis.append(0)
Q = []  # The queue

def bfs(node, G, dist, vis, Q):
    vis[node] = 1
    Q.append(node)
    while len(Q)!=0:
        node = Q[0]
        Q.pop(0)
        for i in range(len(G[node])):  # Search through the node's unvisited neighbours
            if vis[G[node][i]] == False:
                vis[G[node][i]] = True
                dist[G[node][i]] = dist[node]+1
                Q.append(G[node][i])

bfs(s, G, dist, vis, Q)

for i in range(1, n+1):
    if dist[i]==0 and i!=s:
        print(-1)
    else:
        print(dist[i])