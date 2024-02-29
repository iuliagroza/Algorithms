/// This code is contributed by @iuliagroza

/// Time Complexity: O(n*log2(n))
/// Space Complexity: O(n) (no additional space)

#include <iostream>

#define nMax 100001

void Quick_Sort(int a[], int left, int right)
{
    int i=left, j=right, mid=(left+right)/2;
    int piv=a[mid];
    while(i<=j)
    {
        while(a[i]<piv)
            i++;
        while(a[j]>piv)
            j--;
        if(i<=j)
        {
            std::swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(i<right)
        Quick_Sort(a, i, right);
    if(j>left)
        Quick_Sort(a, left, j);
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
    Quick_Sort(a, 1, n);
    for(int i=1; i<=n; i++)
        std::cout << a[i] << ' ';
    return 0;
}
