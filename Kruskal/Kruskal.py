# This code is contributed by @MahmoudFettal

# Time Complexity: O(|E|*log|V|)/O(|E|*log|E|), where |V| is the number of vertices and |E| the number of edges
# Additional Space: O(|V|)

n = 5  # The number of nodes
edges = [(1,2,1),(1,3,5),(2,3,6),(2,4,7),(3,5,3),(3,4,4),(4,5,8),(1,5,2)]  # Each edge is represented by a tuple that contains (node1, node2, weight)

# A quick sort for the weights
def sort_weights(L):
    if len(L) < 2:
            return L
    T,R,M = [],[],[]
    index = L[len(L)//2][2]
    for i in L:
        if i[2] < index:
            T.append(i)
        elif i[2] > index:
            R.append(i)
        else:
            M.append(i)
    return sort_weights(T) + M + sort_weights(R)

# Check if the edge will create a cycle
def cycle_check(tree,checked,a,b):
    for i in checked:
        if i != a and i!=b:
            truth = 2
            for j in tree:
                if i in [j[0],j[1]] and a in [j[0],j[1]]:
                    truth -= 1
                elif i in [j[0],j[1]] and b in [j[0],j[1]]:
                    truth -= 1
                if truth == 0:
                    return True
    return False

# The algorithm
def Kruskal(edges):
    checked = []
    tree    = []
    edges   = sort_weights(edges)
    for i in edges:
        if not(cycle_check(tree,checked,i[1],i[0])):
            tree.append(i)
            checked = list(set(checked+[i[0]]+[i[1]]))
    return tree

# Test
print(Kruskal(edges))