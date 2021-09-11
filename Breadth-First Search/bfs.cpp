/// This code is contributed by @iuliagroza

/// Time Complexity: O(|V|+|E|), where |V| is the number of vertices and |E| the number of edges
/// Space Complexity: O(|V|)

/// Shortest path (minimum number of edges) between a source node and all the others using BFS in a directed graph
#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

#define nMax 100005

void bfs(int node, std::bitset<nMax> vis, std::queue<int> Q, int d[], std::vector<int> G[])
{
    vis[node] = 1;  /// We mark the vertex as visited
    Q.push(node);  /// We push it into the queue
    while(!Q.empty())
    {
        node = Q.front();
        Q.pop();
        for(auto i:G[node])
            if(!vis[i])  /// Searching for unvisited neighbours
            {
                d[i] = d[node]+1;  /// Update the distance of i
                vis[i] = 1;
                Q.push(i);
            }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, m, s;
    std::cin >> n >> m >> s;

    std::vector<int> G[nMax];  /// Our graph is represented as a list (vector) of adjacency
    while(m--)
    {
        int x, y;
        std::cin >> x >> y;
        G[x].push_back(y);
    }

    int d[nMax]={0};
    std::queue<int> Q;
    std::bitset<nMax> vis;

    bfs(s, vis, Q, d, G);

    for(int i=1; i<=n; i++)
        if(d[i]==0 && i!=s)  /// If the distance to a node is 0 and this is not the source node, then it means the two are not in the same connected component
            std::cout << "-1 ";
        else
            std::cout << d[i] << " ";
    return 0;
}
