/// This code is contributed by @iuliagroza

/// Time Complexity: O(n*m), where n is the length of the A sequence and m the length of the B sequence.
/// Additional Space: O(n*m)

#include <iostream>
#include <vector>

#define nMax 1050

int lcs[nMax][nMax];  /// Declared globally just to not do stack overflow

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, m;
    std::cin >> n >> m;

    int A[nMax];
    for(int i=1; i<=n; i++)
        std::cin >> A[i];

    int B[nMax];
    for(int i=1; i<=m; i++)
        std::cin >> B[i];

    for(int i=1; i<=n; i++)  /// Applying the recurrence. The DP structure being declared globally, it is already initialized with 0
        for(int j=1; j<=m; j++)
            if(A[i]==B[j])
                lcs[i][j] = lcs[i-1][j-1]+1;
            else
                lcs[i][j] = std::max(lcs[i-1][j], lcs[i][j-1]);

    int i=n, j=m;
    std::vector<int> sol;
    while(i && j)  /// Building the solution vector
    {
        if(A[i]==B[j])
        {
            sol.push_back(A[i]);  /// It is inversely memorated because we have to start from the maximum LCS
            i--;
            j--;
        }
        else if(lcs[i-1][j] < lcs[i][j-1])
            j--;
        else
            i--;
    }

    std::cout << sol.size() << "\n";
    std::vector<int>::reverse_iterator it;
    for(it=sol.rbegin(); it!=sol.rend(); it++)  /// Inversely output the vector to show it in ascending order
        std::cout << *it << " ";
    return 0;
}
