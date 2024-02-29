/// This code is contributed by @iuliagroza

/// Time Complexity: O(|E|*log|V|)/O(|E|*log|E|), where |V| is the number of vertices and |E| the number of edges
/// Additional Space: O(|V|)

#include <iostream>
#include <vector>
#include <algorithm>

#define nMax 400005

struct edge {
    int a, b, d;
} v[nMax];

bool cmp(edge x, edge y)
{
    return x.d < y.d;
}

int Find(int x, int p[])  /// Find the set of x function for DSU
{
    /// Height compression algorithm
    int r=x;
    while(r!=p[r])
        r=p[r];
    while(p[x]!=r)
    {
        int tmp=p[x];
        p[x]=r;
        x=tmp;
    }
    return r;
}

void Union(int x, int y, int p[])  /// Unify the sets of x and y for DSU
{
    int rx=Find(x, p);
    int ry=Find(y, p);
    if(rx!=ry)
        p[rx]=ry;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, m;
    std::cin >> n >> m;

    for(int i=1; i<=m; i++)
        std::cin >> v[i].a >> v[i].b >> v[i].d;

    std::sort(v+1, v+m+1, cmp);  /// Sort the edges in non-decreasing order

    int p[nMax]={0};  /// Establish the parents of each vertex - they're initially each own's parent
    for(int i=1; i<=n; i++)
        p[i]=i;

    int cost=0;
    std::vector<std::pair<int, int>> sol;
    for(int i=1; i<=m && sol.size()<(n-1); i++)  /// DSU
        if(Find(v[i].a, p)!=Find(v[i].b, p))
        {
            cost+=v[i].d;
            Union(v[i].a, v[i].b, p);
            sol.push_back({v[i].a, v[i].b});
        }

    std::cout << cost << '\n' << n-1 << '\n';
    for(int i=0; i<n-1; i++)
        std::cout << sol[i].first << ' ' << sol[i].second << '\n';
    return 0;
}
