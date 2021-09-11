/// This code is contributed by @iuliagroza

/// Time Complexity: O(|E|*log |V|), where |V| is the number of vertices and |E| the number of edges
/// Additional Space: O(|V|)

/// We consider the first node to be the source and calculate the distance to 2, 3, ..., n in a directed graph

#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

#define nMax 50005

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> G[nMax];  /// List of adjacency
    while(m--)
    {
        int x, y, dist;
        std::cin >> x >> y >> dist;
        G[x].push_back({y, dist});
    }

    std::priority_queue<std::pair<int, int>> Q;  /// First parameter of each pair is the 1-i distance in order to establish the priority by it
    Q.push({0, 1});

    int d[nMax]={0};
    const int INF=1e9;
    for(int i=2; i<=n; i++)
    {
        d[i]=-1e9;
        Q.push({d[i], i});
    }

    std::bitset<nMax> vis;
    while(!Q.empty())
    {
        if(!vis[Q.top().second])
        {
            int x = Q.top().second;
            for(auto i:G[x])
                if(-i.second+d[x]>d[i.first])  /// Found x as an intermediate node that improves the distance between 1 and i
                {
                    Q.push({-i.second+d[x], i.first});
                    d[i.first] = -i.second+d[x];
                }
            vis[x]=1;
        }
        else
            Q.pop();
    }

    for(int i=2; i<=n; i++)
        if(d[i]!=-INF)
            std::cout << -d[i] << " ";
        else  /// There is no access to this node
            std::cout << "0 ";
    return 0;
}
