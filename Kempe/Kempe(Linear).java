//This code is contributed by Riyazul555

// Time Complexity = O(N*(N+M))   N represents the number of vertices in the graph.
// Space Complexity = O(N+M)      M represents the number of edges in the graph.


import java.io.*;
import java.util.*;

public class GraphColoring {
    static final int nMax = 25;

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("pc.in"));
        BufferedWriter fout = new BufferedWriter(new FileWriter("pc.out"));

        StringTokenizer st = new StringTokenizer(fin.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        List<Integer>[] G = new ArrayList[nMax];
        for (int i = 0; i < nMax; i++) {
            G[i] = new ArrayList<>();
        }

        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(fin.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            G[x].add(y);
            G[y].add(x);
        }

        List<Integer> vert = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            vert.add(i);
        }

        boolean moreColors = true;
        int solk = 0;
        int[] colk = new int[nMax];
        for (int k = 1; k <= n && moreColors; k++) {
            int stSz = 0;
            int[] st = new int[nMax];
            int[] gr = new int[nMax];
            Arrays.fill(gr, 0);

            for (int i = 0; i < n; i++) {
                gr[i] = G[i].size();
            }

            while (stSz < n) {
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    if (gr[i] > -1 && gr[i] < k) {
                        gr[i] = -1;
                        st[stSz++] = i;
                        for (int j : G[i]) {
                            gr[j]--;
                        }
                        cnt++;
                    }
                }

                if (cnt == 0) {
                    int pos = 0;
                    while (gr[pos] == -1 && pos < n - 1) {
                        pos++;
                    }
                    gr[pos] = -1;
                    st[stSz++] = pos;
                    for (int j : G[pos]) {
                        gr[j]--;
                    }
                }
            }

            int[] col = new int[nMax];
            Arrays.fill(col, -1);

            for (int i = stSz - 1; i >= 0; i--) {
                boolean[] ap = new boolean[k];
                for (int j : G[st[i]]) {
                    if (col[j] >= 0) {
                        ap[col[j]] = true;
                    }
                }
                int ncol = 0;
                while (ap[ncol] && ncol < k) {
                    ncol++;
                }

                if (ncol < k) {
                    col[st[i]] = ncol;
                } else {
                    col[st[i]] = -2;
                }
            }

            boolean ok = true;
            int maxCol = -1;

            for (int i = 0; i < n && ok; i++) {
                if (col[i] < 0) {
                    ok = false;
                }
                maxCol = Math.max(maxCol, col[i]);
            }

            if (ok) {
                solk = maxCol + 1;
                System.arraycopy(col, 0, colk, 0, n);
                moreColors = false;
            }
        }

        fout.write(solk + "\n");
        for (int i = 0; i < n; i++) {
            fout.write(colk[i] + " ");
        }

        fin.close();
        fout.close();
    }
}
