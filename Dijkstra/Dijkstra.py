# This code is contributed by @MahmoudFettal

# Time Complexity: O(|E|*log |V|), where |V| is the number of vertices and |E| the number of edges
# Additional Space: O(|V|)

n = 6  # The number of nodes
edges = [(1, 2, 3), (1, 3, 2), (2, 4, 6), (2, 5, 5), (3, 4, 3), (3, 6, 10), (3, 4, 3), (4, 5, 6),
         (5, 6, 2)]  # Each edge is represented by a tuple that contains (node1, node2, weight)

# First, we need to create the graph
graph = {}  # The graph will be a dictionary
infinty = float("inf")
for i in range(n):
    graph[i + 1] = {}
for i in edges:
    graph[i[0]][i[1]] = i[2]


# Some functions to make the code easier to read
# possible_paths gives the possible nodes you can pass from that aren't checked already
def possible_paths(checked, related):
    result = []
    for i in related:
        if not (i in checked):
            result.append(i)
    return result


# short_roads gives the node with the smaller wait that isn't checked
def short_road(table, checked):
    for i in table:
        if not (i[0] in checked):
            mini, key, n = i[1], i[0], len(table)
            break
    for i in range(n):
        if table[i][1] < mini and not (i + 1 in checked):
            mini, key = table[i][1], table[i][0]
    return key


# Now, we create Dijkstra's algorithm
def dijkstras(graph, start, end):
    checked = []
    # The table will contain the shortest road to each node
    table = [[start, 0, '']]
    for i in range(2, n + 1):
        table.append([i, infinty, ''])
    while len(checked) < n:
        key = short_road(table, checked)
        nodes = graph[key].keys()  # The nodes form the node key
        checked.append(key)
        nodes = possible_paths(checked, list(nodes))
        for i in nodes:
            if table[i - 1][1] > table[key - 1][1] + graph[key][i]:
                table[i - 1][1] = table[key - 1][1] + graph[key][i]
                table[i - 1][2] = key
    # The shortcut will cross backward the table to find the smaller path
    shortcut = [end]
    print(table)
    while True:
        shortcut.append(table[shortcut[-1] - 1][2])
        if shortcut[-1] == start:
            break
    shortcut.reverse()
    return shortcut


print(dijkstras(graph, 1, 6))