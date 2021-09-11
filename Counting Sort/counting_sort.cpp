/// This code is contributed by @iuliagroza

/// Time Complexity: O(Max-Min), where Max and Min are the maximum, respectively the minimum value of the array
/// Additional Space: O(Max)

#include <iostream>

#define nMax 100001

void Counting_Sort(int& n, int a[])
{
    int Min=a[0], Max=a[0], fr[nMax]={0};
    for(int i=0; i<n; i++)
    {
        fr[a[i]]++;
        Max = std::max(Max, a[i]);
        Min = std::min(Min, a[i]);
    }
    int k=0;
    for(int i=Min; i<=Max; i++)
        for(int j=0; j<fr[i]; j++)
            a[k++]=i;
    n=k;
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
    Counting_Sort(n, a);
    for(int i=0; i<n; i++)
        std::cout << a[i] << ' ';
    return 0;
}
