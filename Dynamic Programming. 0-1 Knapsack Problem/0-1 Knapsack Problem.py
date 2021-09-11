# This code is contributed by @iuliagroza

# Time Complexity: O(n*W)
# Space Complexity: O(n) (optimized)

n = 6
maximum_weight = 10
items = [[3, 7], [3, 4], [1, 2], [1, 9], [2, 4], [1, 5]]  # items[i][0] is the weight of the item i and the items[i][1] is its value

total_value = 0
dp = []
for i in range(maximum_weight+1):  # initialize the dp structure (list) with maximum_weight 0 elements
    dp.append(0)

for i in range(0, n):
    for j in range(maximum_weight-items[i][0], -1, -1):
        if dp[j+items[i][0]] < dp[j]+items[i][1]:  # Recurrence's third branch
            dp[j + items[i][0]] = dp[j] + items[i][1]
            total_value = max(total_value, dp[j + items[i][0]])

print(total_value)