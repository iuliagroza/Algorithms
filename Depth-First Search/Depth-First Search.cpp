/// This code is contributed by @iuliagroza

/// Time Complexity: O(|V|+|E|), where |V| is the number of vertices and |E| the number of edges
/// Space Complexity: O(|V|)

/// Calculate the number of connected components using DFS in an undirected graph

#include <iostream>
#include <vector>
#include <bitset>

#define nMax 100005

void dfs(int nod, std::bitset<nMax>& vis, std::vector<int> G[])
{
    vis[nod]=1;
    for(auto i:G[nod])
        if(!vis[i])
            dfs(i, vis, G);  /// Recursive call for node's neighbour
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, m;
    std::cin >> n >> m;

    std::vector<int> G[nMax];
    while(m--)
    {
        int x, y;
        std::cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int connected = 0;
    std::bitset<nMax> vis;
    for(int i=1; i<=n; i++)
        if(!vis[i])
        {
            connected++;  /// Another connected component is detected
            dfs(i, vis, G);
        }

    std::cout << connected;
    return 0;
}
