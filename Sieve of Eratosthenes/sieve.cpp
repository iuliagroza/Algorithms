/// This code is contributed by @iuliagroza

/// Time Complexity: O(n*log(log n)) - classical
                 /// O(n) - optimized
/// Space Complexity: O(n)

#include <iostream>

void Sieve(int n)
{
    bool ok[n+5]={0};
    ok[0]=ok[1]=1;
    for(int i=4; i<=n; i+=2)  /// All the even values apart from 2 are marked
        ok[i]=1;
    for(int i=3; i*i<=n; i+=2)   /// Check for all prime numbers
        if(!ok[i])
            for(int j=i*i; j<=n; j+=2*i)  /// Mark their unencountered multiples
                ok[j]=1;
    for(int i=1; i<=n; i++)
        std::cout << i << ' ' << ok[i] << '\n';  /// If ok[i] is equal to 0, it is prime
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    std::cin >> n;
    Sieve(n);
    return 0;
}
