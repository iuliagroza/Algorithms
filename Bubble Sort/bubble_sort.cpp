/// This code is contributed by @iuliagroza

/// Time Complexity: O(n^2)
/// Space Complexity: O(n)

#include <iostream>

#define nMax 100001

void Bubble_Sort(int n, int a[])
{
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(a[j]>a[j+1])
                std::swap(a[j], a[j+1]);
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, a[nMax];
    std::cin >> n;
    for(int i=0; i<n; i++)
        std::cin >> a[i];
    Bubble_Sort(n, a);
    for(int i=0; i<n; i++)
        std::cout << a[i] << ' ';
    return 0;
}
