/// This code is contributed by @iuliagroza

/// Time Complexity: O(n)
/// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <algorithm>

int Linear_Search(std::vector<int> v, int element)
{
    for(int i=0; i<v.size(); i++)
        if(v[i]==element)
            return i;  /// We return the position of the element equal to our searched value
    return -1; /// If not found, -1 is returned
}

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
    int search_element = 16; /// Random value to search
    int index = Linear_Search(v, search_element);
    std::cout << index;
    return 0;
}
