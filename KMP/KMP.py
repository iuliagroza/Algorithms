# This code is contributed by @iuliagroza

# Time complexity: O(n), where n is the length of the text
# Additional Space: O(m), where m is the length of the pattern

def KMP(text, pattern):
    n = len(pattern)
    m = len(text)
    j = 0
    nxt = {}  # Storing the precalculated number of letters to skip in a dictionary
    nxt[0] = 0
    for i in range(1, n):
        while j>0 and pattern[i]!=pattern[j]:  # If we find the suffix matching the prefix
            j = nxt[j-1]
        if pattern[i] == pattern[j]:  # Skip the letter if it is the same
            j += 1
        nxt[i] = j
    j = 0
    ocr = []
    # Slide the window to find the occurrences
    for i in range(m):
        while j>0 and text[i]!=pattern[j]:
            j = nxt[j-1]
        if text[i] == pattern[j]:
            j += 1
        if j == n:
            ocr.append(i - n + 1);
            j = nxt[n-1]
    print(ocr)

pattern = "ABA"
text = "CABBCABABAB"

KMP(text, pattern)