# This code is contributed by @MahmoudFettal

# Time Complexity: O(|V|*|E|), where |V| is the number of vertices and |E| the number of edges
# Additional Space: O(|V|)

n = 6  # The number of nodes
edges = [(1,2,3),(1,3,2),(2,4,-6),(2,5,5),(3,4,-3),(3,6,-10),(3,4,3),(4,5,6),(5,6,2)]  # Each edge is represented by a tuple that contains (node1, node2, weight)

# First we need to create the graph
graph   = {}  # The graph will be a dict
infinty = float("inf")
for i in range(n):
    graph[i+1] = {}
for i in edges:
    graph[i[0]][i[1]] = i[2]

def bellman_ford(graph, start, end):
    table = [[start,0]]
    for i in range(1,n+1):
        if i != start:
            table.append([i,infinty])
    changes = 1
    while changes != 0:
        changes = 0
        for i in table:
            if i[1] != infinty:
                for j in graph[i[0]]:
                    if table[j-1][1] > i[1] + graph[i[0]][j]:
                        table[j-1][1] = i[1] + graph[i[0]][j]
                        changes += 1
    return table

print(bellman_ford(graph,1,5))