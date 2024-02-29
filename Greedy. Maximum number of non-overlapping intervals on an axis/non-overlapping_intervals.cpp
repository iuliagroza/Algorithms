/// This code is contributed by @iuliagroza

/// Time Complexity: O(n*log n) (sorting)
/// Additional Space: O(n)

/*
Given n plays at a theater with their starting and ending time (expressed as integers), determine the number of non-overlapping full plays a spectator can watch.
(MAXIMUM NUMBER OF NON-OVERLAPPING INTERVALS ON AN AXIS)
ex. IN:
        10
        5 14
        14 17
        8 13
        13 15
        15 17
        3 6
        4 7
        6 9
        11 14
        10 11
    OUT:
        5
We can choose [3, 6], [6, 9], [10, 11], [11, 14] and [14, 17].
*/

#include <iostream>
#include <algorithm>

#define nMax 1001

struct play {
    int start, finish;
} s[nMax], sol[nMax];  /// Storing the plays in a structure array of two ints

bool cmp(play a, play b)  /// Comparator to sort the plays in ascending order by their finish time
{
    return b.finish > a.finish;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    std::cin >> n;
    for(int i=1; i<=n; i++)
        std::cin >> s[i].start >> s[i].finish;
    std::sort(s+1, s+n+1, cmp);  /// Sorting the plays
    int k=1;
    sol[k] = s[1];
    for(int i=1; i<=n; i++)
        if(s[i].start>=sol[k].finish)  /// Adding only the plays with the starting time later than the last seen play's ending time
            sol[++k] = s[i];
    std::cout << k << '\n';  /// Number of non-overlapping plays we can see
    return 0;
}
