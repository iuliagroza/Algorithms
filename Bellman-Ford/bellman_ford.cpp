/// This code is contributed by @iuliagroza

/// Time Complexity: O(|V|*|E|), where |V| is the number of vertices and |E| the number of edges
/// Additional Space: O(|V|)

#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

#define nMax 50005

void Bellman_Ford(int node, int n, bool ok, std::vector<std::pair<int, int>> G[nMax], int dist[])
{
    const int INF=1e9;
    for(int i=2; i<=n; i++)
        dist[i]=INF;  /// Initialize distances with infinity
    dist[node]=0;
    std::queue<int> Q;
    Q.push(node);  /// Push the source node in the queue
    std::bitset<nMax> vis;
    vis[node]=1;
    int nr[nMax]={0};
    while(!Q.empty())  /// BFS - repeat the steps for |V|-1 times
    {
        node = Q.front();
        Q.pop();
        vis[node]=0;
        for(auto i:G[node])
            if(dist[node]+i.second < dist[i.first])
            {
                dist[i.first] = dist[node]+i.second;  /// Found a shorter distance
                nr[i.first]++;
                if(nr[i.first]>n)  /// Check if one optimal distance can be improved ~ we found a negative cycle and exit the function
                {
                    ok=1;
                    return;
                }
                if(!vis[i.first])
                {
                    vis[i.first]=1;
                    Q.push(i.first);
                }
            }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> G[nMax];
    for(int i=1; i<=m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        G[a].push_back({b, c});
    }
    bool ok=0;
    int dist[nMax] = {0};

    Bellman_Ford(1, n, ok, G, dist);

    if(!ok)
        for(int i=2; i<=n; i++)
            std::cout << dist[i] << ' ';
    else
        std::cout << "Negative cycle!";
    return 0;
}
