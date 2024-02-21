/// This code is contributed by @iuliagroza

/// Time Complexity: O(d*(n+b)), where d is the number of digits in the given list, n is the number of elements in the list, and b is the base or bucket size used
/// Space Complexity: O(n+2^d)

/// Optimised with bit operations

/*
Sort a N elements vector generated by the following recurrence:
v[i] = B, i = 1
v[i] = (A * v[i-1] + B) % C, 2 ≤ i ≤ N
N, A, B, C, given
*/

#include <iostream>
#include <vector>

void Radix_Sort(vector<int>& v)
{
    vector<int> cnt(256); 
    vector<int> out((int)v.size()); 
    for(int bit=0; bit<=31; bit+=8)
    {
        for(auto& x:v)
            cnt[(x>>bit)&255]++; // Right shift and perform '&' operation
        for(int i=1; i<256; i++)
            cnt[i]+=cnt[i-1]; // Give alternating pairs of the array same value
        for(int i=(int)v.size()-1; i>=0; i--)
            out[--cnt[(v[i]>>bit)&255]]=v[i];
        v=out;
        fill(cnt.begin(), cnt.end(), 0);
    }
}

int main()
{
    int n,a,b,c;
    std::cin >> n >> a >> b >> c;
    vector<int> v(n);
    v[0]=b;
    for(int i=1;i<n;i++)
        v[i]=(1LL*a*v[i-1]+b)%c;
    Radix_Sort(v);
    for(int i=0; i<(int)v.size(); i+=10)
        std::cout<< v[i] << ' ';
    return 0;
}
