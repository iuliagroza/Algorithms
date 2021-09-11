/// This code is contributed by @iuliagroza

/// Time Complexity: O(n*log2(n))
/// Additional Space: O(n)

#include <iostream>

#define nMax 100001

void Merge(int a[], int left, int mid, int right)
{
    int i=left, j=mid+1, k=0, b[nMax];
    while(i<=mid && j<=right)
        if(a[i]<a[j])
            b[++k]=a[i++];
        else
            b[++k]=a[j++];
    while(i<=mid)
        b[++k]=a[i++];
    while(j<=right)
        b[++k]=a[j++];
    for(i=left; i<=right; i++)
        a[i]=b[i-left+1];
}

void Merge_Sort(int a[], int left, int right)
{
    if(left<right)
    {
        int mid = (left+right)/2;
        Merge_Sort(a, left, mid);
        Merge_Sort(a, mid+1, right);
        Merge(a, left, mid, right);
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
    Merge_Sort(a, 1, n);
    for(int i=1; i<=n; i++)
        std::cout << a[i] << ' ';
    return 0;
}
