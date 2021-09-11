/// This code is contributed by @iuliagroza

/// Time Complexity: O(|V|+|E|) (from BFS)
/// Space Complexity: O(|V|^2)

#include <iostream>
#include <set>
#include <vector>

#define nMax 50005

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, m;
    std::cin >> n >> m;

    int in[nMax]={0};
    std::vector<int> G[nMax];
    while(m--)
    {
        int x, y;
        std::cin >> x >> y;
        G[x].push_back(y);
        in[y]++;  /// Find the in-degree of each vertex
    }

    std::multiset<int> S;
    for(int i=1; i<=n; i++)
        if(in[i]==0)
            S.insert(i);  /// Insert all the 0 in-degree nodes in a multiset

    std::vector<int> ts;
    while(!S.empty())  /// BFS
    {
        int node = *S.begin();
        S.erase(S.begin());
        ts.push_back(node);  /// ts is the solution vector
        for(auto i:G[node])
            if(--in[i]==0)
                S.insert(i);
    }
    for(auto i:ts)
        std::cout << i << ' ';
    return 0;
}
