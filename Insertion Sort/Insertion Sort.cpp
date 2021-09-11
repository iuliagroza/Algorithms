/// This code is contributed by @iuliagroza

/// Time Complexity: O(n^2)
/// Space Complexity: O(1)

#include <iostream>
#define nMax 1005

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    /// Input
    int n;
    std::cin >> n;

    int a[nMax];
    for(int i=1; i<=n; i++)
        std::cin >> a[i];

    /// Searching for elements that are smaller than their predecessor
    for(int i=2; i<=n; i++)
    {
        int key = a[i], j = i-1;

        /// Moving the found element on the right position
        while(j>0 && a[j]>key)
            a[j+1] = a[j--];

        a[j+1] = key;
    }

    /// Output
    for(int i=1; i<=n; i++)
        std::cout << a[i] << ' ';
}
