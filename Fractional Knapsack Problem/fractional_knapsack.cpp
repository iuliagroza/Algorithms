/// This code is contributed by @iuliagroza

/// Time Complexity: O(n*log n) (sorting)

#include <iostream>
#include <algorithm>

#define nMax 1001

struct object{
    float w, v, profit;
} a[nMax];

bool cmp(object x, object y)
{
    return y.profit < x.profit;  /// Comparator to sort the array in ascending order by the items' profit
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    float wmax;
    std::cin >> n >> wmax;
    for(int i=1; i<=n; i++)
    {
        std::cin >> a[i].w >> a[i].v;
        a[i].profit = a[i].v/a[i].w;  /// Calculate the profit
    }
    std::sort(a+1, a+n+1, cmp);  /// Sort the items
    float s=0, weight=wmax;
    for(int i=1; i<=n; i++)
    {
        if(weight>a[i].w)
        {
            s+=a[i].v;
            weight -= a[i].w;
        }
        else
        {
            s+=(float)(a[i].v*weight)/a[i].w;  /// Convert into float for the fractional value
            break;  /// If we got here it means that this is the last item that can (partially) fit into the knapsack
        }
    }
    std::cout << s;
    return 0;
}
