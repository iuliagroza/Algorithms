# This code is contributed by @iuliagroza

# Time Complexity: O(n * log n) (sorting)
# Additional Space: O(n)

# Given n plays at a theater with their starting and ending time (expressed as integers), determine the number of non-overlapping full plays a spectator can watch.
# (MAXIMUM NUMBER OF NON-OVERLAPPING INTERVALS ON AN AXIS)
# ex. IN:
#         10
#         5 14
#         14 17
#         8 13
#         13 15
#         15 17
#         3 6
#         4 7
#         6 9
#         11 14
#         10 11
#     OUT:
#         5
# We can choose [3, 6], [6, 9], [10, 11], [11, 14] and [14, 17].

n = 10
plays = [[5, 14], [14, 17], [8, 13], [13, 15], [15, 17], [3, 6], [4, 7], [6, 9], [11, 14], [10, 11]]

from operator import itemgetter

plays = sorted(plays, key=itemgetter(1))  # Sorting the plays by their ending time

solution = []
solution.append(plays[0])

for i in range(1, len(plays)):
    if plays[i][0] >= solution[len(solution)-1][1]:  # Adding only the plays that have the starting time later than the ending time of the last seen play
        solution.append(plays[i])

print(len(solution))
