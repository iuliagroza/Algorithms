/// This code is contributed by @iuliagroza

/// Time complexity: O(n), where n is the length of the text
/// Additional Space: O(m), where m is the length of the pattern

/// For the sake of simplicity, the text is just a word (n<=50.000)
#include <iostream>
#include <cstring>
#include <vector>

#define nMax 500005

void KMP(std::string text, std::string pattern)
{
    int n=pattern.size(), m=text.size(), j=0, nxt[nMax]={0};
    nxt[0]=0;
    /// Precalculate the numbers of letters we can skip for every prefix
    for(int i=1; i<n; i++)
    {
        while(j>0 && pattern[i]!=pattern[j])
            j=nxt[j-1];
        if(pattern[i]==pattern[j])
            j++;
        nxt[i]=j;
    }
    j=0;
    std::vector<int> ocr;
    /// Sliding the window (just like in the naive solution) using nxt[] in order to find the pattern's occurences
    for(int i=0; i<m; i++)
    {
        while(j>0 && text[i]!=pattern[j])  /// If the characters do not match, skip to the next index
            j=nxt[j-1];
        if(text[i]==pattern[j])  /// The characters match
            j++;
        if(j==n)
            ocr.push_back(i-n+1); /// We found an occurrence
    }
    for(auto i : ocr)
        std::cout << i << ' ';
}

int main()
{
    std::string pattern, text;
    std::cin >> pattern >> text;
    KMP(text, pattern);
    return 0;
}
