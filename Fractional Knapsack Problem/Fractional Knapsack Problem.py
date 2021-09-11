# This code is contributed by @iuliagroza

# Time Complexity: O(n*log n) (sorting)

n = 4
maximum_weight = 30
items = [[10, 60], [5, 50], [12, 60], [20, 140]]  # items[i][0] is the weight of the item i and the items[i][1] is its value
profit = []

for i in range(len(items)):
    items[i].append(items[i][0]/items[i][1])  # Calculate the profit of each item: items[i][2]

from operator import itemgetter

items = sorted(items, key=itemgetter(2))  # Sort items by items[i][2]

total_value = 0
current_weight = maximum_weight
for i in range(len(items)):
    if current_weight >= items[i][0]:  # If the whole item fits into the knapsack
        current_weight -= items[i][0]
        total_value += items[i][1]  # Add its value
    else:
        total_value += (items[i][1]*current_weight)/items[i][0]  # The fractional weight is equal to the current weight
        break

print(total_value)