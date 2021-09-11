# This code is contributed by @MahmoudFettal

# Time Complexity: O(|V|+|E|) (from BFS)
# Space Complexity: O(|V|^2)

edges = [[1, 2], [1, 3], [2, 5], [3, 2], [3, 4], [5, 4]]
graph = dict()

for i in range(n):
    graph.update({i + 1: []})
for i in edges:
    graph[i[0]].append(i[1])

# graph = {1:[4],2:[4],3:[1,2],4:[7,8],5:[1,4,6],6:[11,10],7:[9],8:[9,10],9:[12],10:[12,13],11:[10],12:[],13:[]}  # A bigger graph

n = len(graph)  # Nodes number


# Function given the possible moves taken in consideration already checked nodes
def available(nodes, path):
    result = []
    for i in nodes:
        if not (i in path):
            result.append(i)
    return result


# Follow a path in the graph function
def follow_the_path(graph, node, path):
    possible = available(graph[node], path)
    if possible == []:
        path.append(node)
    else:
        for i in possible:
            follow_the_path(graph, i, path)
        path.append(node)


# The algorithm of topological sorting
def topological_sort(graph):
    topo_sort = []
    while len(topo_sort) < n:
        for i in range(1, n + 1):
            if not (i in topo_sort):
                follow_the_path(graph, i, topo_sort)
    topo_sort.reverse()
    return topo_sort


# Test
print(topological_sort(graph))