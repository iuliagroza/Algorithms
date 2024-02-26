from collections import defaultdict
from typing import List, Dict

class Graph:
    """
    Represents a graph data structure using an adjacency list.
    """

    def __init__(self, vertices: int):
        """
        Initializes a graph with the specified number of vertices.

        Args:
            vertices (int): The number of vertices in the graph.
        """
        self.num_vertices: int = vertices
        self.graph: Dict[int, List[int]] = defaultdict(list)  # Adjacency list

    def add_edge(self, u: int, v: int) -> None:
        """
        Adds an edge between two vertices in the graph (undirected).

        Args:
            u (int): The first vertex.
            v (int): The second vertex.
        """
        self.graph[u].append(v)
        self.graph[v].append(u)  

    def _dfs_util(self, vertex: int, visited: List[bool]) -> None:
        """
        Helper function for Depth-First Search (DFS) traversal.

        Args:
            vertex (int): The starting vertex for the DFS.
            visited (List[bool]): Keeps track of visited vertices.
        """
        visited[vertex] = True
        for neighbor in self.graph[vertex]:
            if not visited[neighbor]:
                self._dfs_util(neighbor, visited)

    def is_connected(self) -> bool:
        """
        Checks if the graph is connected.

        Returns:
            bool: True if the graph is connected, False otherwise.
        """
        visited: List[bool] = [False] * self.num_vertices

        # Find a vertex with edges and start DFS 
        for vertex in range(self.num_vertices):
            if len(self.graph[vertex]) > 0:
                self._dfs_util(vertex, visited)
                break  

        # Check if all vertices with edges were reached
        for vertex in range(self.num_vertices):
            if not visited[vertex] and len(self.graph[vertex]) > 0:
                return False
        return True

    def is_eulerian(self) -> int:
        """
        Checks if the graph has an Eulerian circuit or path.

        Returns:
            int:  0 if not Eulerian,
                  1 if Eulerian path exists,
                  2 if Eulerian circuit exists.
        """
        if not self.is_connected():
            return 0

        odd_degree_count = 0
        for vertex in range(self.num_vertices):
            if len(self.graph[vertex]) % 2 != 0:
                odd_degree_count += 1
        return 2 if odd_degree_count == 0 else 1 if odd_degree_count == 2 else 0

    def _count_reachable_vertices(self, start: int, visited: List[bool]) -> int:
        """
        Counts vertices reachable from a given starting vertex using DFS.

        Args:
            start (int): The starting vertex.
            visited (List[bool]): Keeps track of visited vertices.

        Returns:
            int: The count of reachable vertices.
        """
        visited[start] = True
        count = 1
        for neighbor in self.graph[start]:
            if not visited[neighbor]:
                count += self._count_reachable_vertices(neighbor, visited)
        return count

    def is_valid_next_edge(self, u: int, v: int) -> bool:
        """
        Checks if removing edge (u, v) would disconnect the graph. Handles
        the case of self-loops effectively.

        Args:
            u (int): The first vertex.
            v (int): The second vertex.

        Returns:
            bool: True if the edge is valid for removal (i.e., its removal
                  doesn't disconnect the graph), False otherwise. 
        """
        # Edge case: Self-loops can always be removed.
        if len(self.graph[u]) == 1:
            return True

        visited = [False] * self.num_vertices

        # Count vertices reachable from 'u' before removing the edge
        count_before = self._count_reachable_vertices(u, visited.copy())

        # Remove the edge temporarily
        self.graph[u].remove(v)
        self.graph[v].remove(u)

        # Count vertices reachable from 'u' after removing the edge
        count_after = self._count_reachable_vertices(u, visited.copy())

        # Add the edge back
        self.graph[u].append(v)
        self.graph[v].append(u)

        # The edge is valid if the counts are the same
        return count_before == count_after

    def find_eulerian_path(self) -> None:
        """
        Implements Fleury's algorithm to find an Eulerian path or circuit.
        Prioritizes starting at a vertex with odd degree if one exists.
        """
        u = self._find_start_vertex()
        self.eulerian_path = [u]
        self._fleury_util(u)

    def _find_start_vertex(self) -> int:
        """
        Finds the suitable starting vertex for Fleury's algorithm, prioritizing 
        odd-degree vertices.

        Returns:
            int: The appropriate starting vertex.
        """
        for vertex in range(self.num_vertices):
            if len(self.graph[vertex]) % 2 != 0:
                return vertex
        return 0  # If all vertices have even degree, start anywhere

    def _fleury_util(self, u: int) -> None:
        """
        Recursive function to traverse the graph using Fleury's algorithm.
        """
        for v in self.graph[u]:
            if self.is_valid_next_edge(u, v):
                self.eulerian_path.append(v)
                self.graph[u].remove(v)
                self.graph[v].remove(u)
                self._fleury_util(v) 

    def print_eulerian_path(self) -> None:
        """
        Prints the found Eulerian path or circuit.
        """
        for node in self.eulerian_path:
            print(node, end=" -> ")
        print(self.eulerian_path[0]) 

# Example usage
g = Graph(4)
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 2)
g.add_edge(2, 3)

result = g.is_eulerian()
if result == 0:
    print("Graph is not Eulerian")
elif result == 1:
    print("Graph has an Eulerian path")
else:
    print("Graph has an Eulerian circuit")

g.find_eulerian_path()
print("Eulerian Path:")
g.print_eulerian_path()