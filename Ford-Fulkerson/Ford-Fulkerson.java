//This code was contributed by Riyazul555

//Time Complexity = O(M * (V + E))  
//Space Complexity = O(V^2)         

import java.io.*;
import java.util.*;

public class MaxFlow {

    static final int nMax = 1005;

    public static int bfs(ArrayList<Integer>[] G, int n, int[] dad, int[][] C) {
        Queue<Integer> Q = new LinkedList<>();
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
        BufferedWriter fout = new BufferedWriter(new FileWriter(args[1]));

        StringTokenizer st = new StringTokenizer(fin.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        ArrayList<Integer>[] G = new ArrayList[nMax];
        for (int i = 0; i < nMax; i++) {
            G[i] = new ArrayList<>();
        }

        int[][] C = new int[nMax][nMax];
        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(fin.readLine());
            int x = Integer.parseInt(st.nextToken()) + 1;
            int y = Integer.parseInt(st.nextToken()) + 1;
            int c = Integer.parseInt(st.nextToken());
            C[x][y] = c;
            G[x].add(y);
            G[y].add(x);
        }

        int flow = 0;
        int[] dad = new int[nMax];
        while (bfs(G, n, dad, C) != 0) {
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
            Arrays.fill(dad, 0);
        }
        fout.write(Integer.toString(flow));
        fin.close();
        fout.close();
    }
}
