//This code is contributed by Riyazul555

// Time Complexity: O(V * E^2)  where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V^2)     where V is the number of vertices.

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;

public class MaxFlow {

    static int[][] C;
    static ArrayList<Integer>[] G;

    static int bfs(int n, int[] dad) {
        Queue<Integer> Q = new ArrayDeque<>();
        Q.add(1);
        while (!Q.isEmpty()) {
            int nod = Q.poll();
            for (int i : G[nod]) {
                if (dad[i] == 0 && C[nod][i] > 0) {
                    dad[i] = nod;
                    Q.add(i);
                }
            }
        }
        return dad[n];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader(args[0]));
        FileWriter fout = new FileWriter(args[1]);

        String[] tokens = fin.readLine().split(" ");
        int n = Integer.parseInt(tokens[0]);
        int m = Integer.parseInt(tokens[1]);
        C = new int[n + 1][n + 1];
        G = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            G[i] = new ArrayList<>();
        }

        for (int i = 1; i <= m; i++) {
            tokens = fin.readLine().split(" ");
            int x = Integer.parseInt(tokens[0]) + 1;
            int y = Integer.parseInt(tokens[1]) + 1;
            int c = Integer.parseInt(tokens[2]);
            C[x][y] = c;
            G[x].add(y);
            G[y].add(x);
        }

        int flow = 0;
        int[] dad = new int[n + 1];
        while (bfs(n, dad) != 0) {
            for (int i : G[n]) {
                int Min = C[i][n];
                for (int j = i; j != 1; j = dad[j]) {
                    Min = Math.min(Min, C[dad[j]][j]);
                }
                for (int j = i; j != 1; j = dad[j]) {
                    C[dad[j]][j] -= Min;
                    C[j][dad[j]] += Min;
                }
                flow += Min;
                C[i][n] -= Min;
                C[n][i] += Min;
            }
            java.util.Arrays.fill(dad, 0);
        }
        fout.write(flow + "");
        fin.close();
        fout.close();
    }
}
