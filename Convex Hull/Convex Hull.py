# This code is contributed by @iuliagroza

# Time complexity: O(n * log n)
# Space Complexity: O(n)

n = 8
points = [[2.0, 0.0], [0.0, 2.0], [1.0, 3.0], [0.0, 4.0], [3.0, 3.0], [2.0, 6.0], [4.0, 2.0], [4.0, 4.0]]

points = sorted(points)
for i in range(n-2, -1, -1):
    points.append(points[i])

def slope(a, b, c):  # Function that checks if the current point can be added into the convex hull
    return (a[0]-b[0])*(b[1]-c[1])-(b[0]-c[0])*(a[1]-c[1]) < 0

hull = []

for i in range(2*n-1):  # Build the convex hull
    while len(hull)>1 and slope(hull[-2], hull[-1], points[i]):
        hull.pop()
    hull.append(points[i])
hull.pop()  # Remove the last element, because it coincides with the first

print(hull)