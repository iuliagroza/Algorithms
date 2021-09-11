/// This code is contributed by @iuliagroza

/// Time Complexity: O(n*W)
/// Space Complexity: O(n) (optimized)

#include <iostream>

#define nMax 10005

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, W;
    std::cin >> n >> W;
    int w[nMax], v[nMax];
    for(int i=1; i<=n; i++)
        std::cin >> w[i] >> v[i];
    int sol = 0, dp[nMax] = {0};
    for(int i=1; i<=n; i++)
        for(int j=W-w[i]; j>=0; j--)  /// Starting from the maximum possible weight
            if(dp[j+w[i]] < dp[j]+v[i])
            {
                dp[j+w[i]] = dp[j]+v[i];  /// Second case in max
                sol = std::max(sol, dp[j+w[i]]);  /// sol stores the first case in max
            }
    std::cout << sol;  /// sol is actually dp[W]
    return 0;
}
