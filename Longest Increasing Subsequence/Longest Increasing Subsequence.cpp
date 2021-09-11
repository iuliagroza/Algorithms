/// This code is contributed by @iuliagroza

/// Time Complexity: O(n*log n) (efficient)
/// Additional Space: O(n)

/// The following source solves the Longest STRICTLY Increasing Subsequence problem

#include <iostream>

#define nMax 100005

void output(int k, int ind[], int A[])  /// Function used to output the subsequence in increasing order (because it is built from the end)
{
    if(k>0)
    {
        output(ind[k], ind, A);
        std::cout << A[k] << " ";
    }
}

int src(int x, int k, int A[], int last_pos[])  /// Binary search function that searches for the maximum element after our current element that is bigger than it
{
    int sol=0, left=1, right=k;
    while(left <= right)
    {
        int mid = (left+right)>>1;
        if(x > A[last_pos[mid]])
        {
            left = mid+1;
            sol = std::max(sol, mid);
        }
        else
            right = mid-1;
    }
    return sol;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    std::cin >> n;

    int A[nMax];
    for(int i=1; i<=n; i++)
        std::cin >> A[i];

    int last_pos[nMax]={0}, best[nMax]={0};  /// last_pos[] helps us link the elements of the subsequence between them, best[] stores the maximum current length.
    last_pos[0]=0, last_pos[1]=1, best[1]=1;

    int k=1, ind[nMax]={0};
    for(int i=2; i<=n; i++)  /// Solve the problem using the recurrence relation
    {
        int pos = src(A[i], k, A, last_pos);
        ind[i] = last_pos[pos];
        best[i] = pos+1;
        last_pos[pos+1] = i;
        k = std::max(k, best[i]);
    }

    int lst, Max=0;
    for(int i=1; i<=n; i++)  /// Find the maximum length
        if(best[i]>Max)
    {
        Max = best[i];
        lst = i;
    }

    std::cout << Max << '\n';
    output(lst, ind, A);
    return 0;
}
