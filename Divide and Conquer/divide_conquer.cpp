/// This code is contributed by @iuliagroza

/// Time Complexity: O(n) (for the Sum of n Elements problem)
/// Space Complexity: O(n)

/// Sum of n elements using DAC

#include <iostream>

#define nMax 100001

int DAC(int arr[], int start, int finish)
{
    if(start==finish)
        return arr[start];
    else
    {
        int mid = (start+finish)/2;
        int sum1 = DAC(arr, start, mid);
        int sum2 = DAC(arr, mid+1, finish);
        return sum1+sum2;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, a[nMax];
    std::cin >> n;
    for(int i=1; i<=n; i++)
        std::cin >> a[i];
    int sum = DAC(a, 1, n);
    std::cout << sum;
    return 0;
}
