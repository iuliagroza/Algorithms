/// This code is contributed by @iuliagroza

/// Time Complexity: O(n^2)
/// Additional Space: O(1)

#include <iostream>
#include <algorithm>

void selectionSort(int a[], int n)
{
    for(int i=0; i<n-1; i++) {
        int min_index = i; // Minimum value position
        for(int j=i+1; j<n; j++) {
            if (a[min_index] > a[j]) {
                min_index = j;
            }
        std::swap(a[i], a[min_index]);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, a[100];
    std::cin >> n;
    for(int i=0; i<n; i++) {
        std::cin >> a[i];
    }

    selectionSort(a, n);

    for(int i=0; i<n; i++) {
        std::cout << a[i] << ' ';
    }
    return 0;
}
