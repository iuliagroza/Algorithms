/// This code is contributed by @iuliagroza

/// Time complexity: O(log n)

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::vector<int> v;
    int n;
    std::cin >> n;
    for(int i=0; i<n; i++)
    {
        int x;
        std::cin >> x;
        v.push_back(x);
    }
    int value = 16;

    std::sort(v.begin(), v.end()); ///Our array must be sorted

    std::vector<int>::iterator low_it;
    low_it = std::lower_bound(v.begin(), v.end(), value); /// Returns the smallest element bigger or equal to our value
    std::cout << low_it-v.begin() << '\n';

    std::vector<int>::iterator up_it;
    up_it = std::upper_bound(v.begin(), v.end(), value); /// Returns the biggest element smaller or equal to our value
    std::cout << up_it-v.begin() << '\n';

    bool found = 0;
    found = std::binary_search(v.begin(), v.end(), value); /// Binary Search STL function - it returns a bool if a value is found or not
    std::cout << found << '\n';

    return 0;
}
