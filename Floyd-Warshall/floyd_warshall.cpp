/// This code is contributed by @iuliagroza

/// Time Complexity: O(|V|^3), where |V| is the number of vertices
/// Space Complexity: O(|V|^2)

#include <iostream>

#define nMax 105

void Floyd_Warshall(int n, int a[nMax][nMax])
{
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(i!=j && a[i][k] && a[k][j] && (!a[i][j] || a[i][j] > a[i][k]+a[k][j]))
                    a[i][j] = a[i][k]+a[k][j];
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    std::cin >> n;

    int a[nMax][nMax];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            std::cin >> a[i][j];

    Floyd_Warshall(n, a);

    /// The result is the distance matrix of the graph
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            std::cout << a[i][j] << " \n"[j==n];
    return 0;
}
