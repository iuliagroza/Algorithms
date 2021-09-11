/// This code is contributed by @iuliagroza

/// Time complexity: O(n*log n)
/// Space Complexity: O(n)

#include <iostream>
#include <algorithm>
#include <iomanip>

#define nMax 250005
#define p std::pair<double, double>
#define x first
#define y second

p a[nMax], h[nMax];

bool slope(p a, p b, p c)  /// Check if the angle between [a[i], h[j-1]] and [h[j-1], h[j-2]] is less than 180 degrees
{
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x)<0;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    std::cin >> n;
    for(int i=0; i<n; i++)
        std::cin >> a[i].x >> a[i].y;  /// a[] is an array of pairs of double values

    std::sort(a, a+n);  /// Sort a[] in ascending order, by x, then by y
    std::reverse_copy(a, a+n-1, a+n);  ///Append the first n-1 elements in descending order to a[]

    int j=0;
    for(int i=0; i<2*n-1; h[j++]=a[i++])  /// Build the convex hull
        while(j>1 && slope(h[j-2], h[j-1], a[i]))
            j--;

    std::cout << --j << '\n';
    for(int i=0; i<j; i++)
        std::cout << std::fixed << std::setprecision(9) << h[i].x << ' ' << h[i].y << '\n';  /// Output with 9 decimals precision
    return 0;
}
