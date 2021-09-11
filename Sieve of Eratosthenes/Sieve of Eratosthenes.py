# This code is contributed by @iuliagroza

# Time Complexity: O(n*log(log n)) - classical
                 # O(n) - optimized
# Space Complexity: O(n)

import math

def Sieve(n):
    ok = []
    for i in range(n):
        ok.append(0)
    ok[0]=ok[1]=1
    for i in range(4, n, 2):  # Mark all the even values except for 2
        ok[i]=1
    for i in range(3, int(math.sqrt(n)), 2):
        if ok[i]==0:
            for j in range(i*i, n, 2*i):  #Check all the multiples starting from i*i
                ok[j]=1
    for i in range(n):
        print(str(i)+' '+str(ok[i]))  # If ok[i] is equal to 0, it is prime


n = 100

Sieve(n)