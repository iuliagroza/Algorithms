//This code was contributed by Riyazul555


//Time Complexity = O(2^N), where N is the number of vertices
//Space Complexity = O(N + M), where M is the number of edges


import java.io.*;
import java.util.*;

public class ChromaticNumber {

    static final int nMax = 25;
    static final int MOD = 1077563119;

    static void bfs(int nod, List<Integer>[] G, boolean[] viz) {
        Queue<Integer> Q = new LinkedList<>();
        viz[nod] = true;
        Q.add(nod);
        while (!Q.isEmpty()) {
            nod = Q.poll();
            for (int i : G[nod]) {
                if (!viz[i]) {
                    viz[i] = true;
                    Q.add(i);
                }
            }
        }
    }

    static boolean isConnected(int n, int m, List<Integer>[] G, List<Integer> vert) {
        boolean[] viz = new boolean[nMax];
        bfs(vert.get(0), G, viz);
        for (int i : vert) {
            if (!viz[i]) {
                return false;
            }
        }
        return true;
    }

    static boolean isComplete(int n, List<Integer>[] G, List<Integer> vert) {
        for (int i : vert) {
            if (G[i].size() != n - 1) {
                return false;
            }
        }
        return true;
    }

    static long chromaticPolynomial(int k, int n, int m, List<Integer>[] G, List<Integer> vert) {
        if (m == 0) {
            long p = 1;
            for (int i = 1; i <= n; i++) {
                p = (p % MOD * k % MOD) % MOD;
            }
            return p;
        }
        if (isComplete(n, G, vert)) {
            long p = 1;
            for (int i = k - n + 1; i <= k; i++) {
                p = (p % MOD * i % MOD) % MOD;
            }
            return p;
        }
        if (isConnected(n, m, G, vert) && m == n - 1) {
            long p = k % MOD;
            for (int i = 1; i < n; i++) {
                p = (p % MOD * (k - 1) % MOD) % MOD;
            }
            return p;
        }
        List<Integer>[] G1 = new List[nMax];
        for (int i = 0; i < nMax; i++) {
            G1[i] = new ArrayList<>();
        }
        int ind = 0;
        while (G[vert.get(ind)].size() == 0) {
            ind++;
        }
        int p1 = vert.get(ind);
        int p2 = G[p1].get(G[p1].size() - 1);
        for (int i : vert) {
            for (int j : G[i]) {
                if ((i == p1 && j == p2) || (i == p2 && j == p1)) {
                    continue;
                }
                G1[i].add(j);
            }
        }
        List<Integer> vert2 = new ArrayList<>();
        for (int i : vert) {
            if (i != p2) {
                vert2.add(i);
            }
        }
        List<Integer>[] G2 = new List[nMax];
        for (int i = 0; i < nMax; i++) {
            G2[i] = new ArrayList<>();
        }
        for (int i : vert2) {
            for (int j : G1[i]) {
                if (j == p2) {
                    if (!G2[i].contains(p1)) {
                        G2[i].add(p1);
                    }
                } else {
                    if (!G2[i].contains(j)) {
                        G2[i].add(j);
                    }
                }
            }
            if (i == p1) {
                for (int j : G1[p2]) {
                    if (!G2[i].contains(j)) {
                        G2[i].add(j);
                    }
                }
            }
        }
        int sz = 0;
        for (int i : vert2) {
            sz += G2[i].size();
        }
        sz /= 2;
        return (chromaticPolynomial(k, n, m - 1, G1, vert) % MOD - chromaticPolynomial(k, n - 1, sz, G2, vert2) % MOD + MOD) % MOD;
    }

    static int chromaticNumber(int n, int m, List<Integer>[] G, List<Integer> vert) {
        for (int i = 1; i <= n; i++) {
            if (chromaticPolynomial(i, n, m, G, vert) != 0) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("pc.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("pc.out"));

        int n, m;
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        List<Integer>[] G = new List[nMax];
        for (int i = 0; i < nMax; i++) {
            G[i] = new ArrayList<>();
        }

        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            G[x].add(y);
            G[y].add(x);
        }

        List<Integer> vert = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            vert.add(i);
        }

        int k = chromaticNumber(n, m, G, vert);
        pw.println(k);

        int st_sz = 0;
        int[] st = new int[nMax];
        int[] gr = new int[nMax];
        for (int i = 0; i < n; i++) {
            gr[i] = G[i].size();
        }
        while (st_sz < n) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (gr[i] > -1 && gr[i] < k) {
                    gr[i] = -1;
                    st[st_sz++] = i;
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
                st[st_sz++] = pos;
                for (int j : G[pos]) {
                    gr[j]--;
                }
            }
        }
        int[] col = new int[nMax];
        Arrays.fill(col, -1);
        for (int i = st_sz - 1; i >= 0; i--) {
            boolean[] ap = new boolean[nMax];
            for (int j : G[st[i]]) {
                if (col[j] != -1) {
                    ap[col[j]] = true;
                }
            }
            int ncol = 0;
            while (ap[ncol] && ncol < k) {
                ncol++;
            }
            if (ncol < k) {
                col[st[i]] = ncol;
            }
        }
        for (int i = 0; i < n; i++) {
            pw.print(col[i] + " ");
        }

        br.close();
        pw.close();
    }
}
