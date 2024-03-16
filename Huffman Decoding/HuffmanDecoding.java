// This code is contributed by Riyazul555

// Time Complexity: O(N log N)  N is the size of the input file
// Space Complexity: O(N)       N is the size of the input file



import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Comparator;
import java.util.PriorityQueue;

public class HuffmanDecoding {
    private static final int nMax = 20005;

    public static void dfs(int nod, String val, int[][] G, String[] cod) {
        if (G[nod][0] == -1) {
            cod[nod] = val;
            return;
        }
        dfs(G[nod][0], val + "0", G, cod);
        dfs(G[nod][1], val + "1", G, cod);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader(args[0]));
        BufferedWriter fout = new BufferedWriter(new FileWriter(args[1]));
        int n = Integer.parseInt(fin.readLine());
        String[] v = new String[nMax];
        int[] fr = new int[nMax];
        int[] val = new int[nMax];
        Comparator<Integer> compare = (a, b) -> {
            return ((fr[a] > fr[b]) || (fr[a] == fr[b] && val[a] > val[b])) ? 1 : -1;
        };
        PriorityQueue<Integer> Q = new PriorityQueue<>(compare);
        for (int i = 0; i < n; i++) {
            char ch = (char) fin.read();
            v[i] = Character.toString(ch);
            fin.read();
            fr[i] = Integer.parseInt(fin.readLine());
            val[i] = i;
            Q.add(i);
        }
        int[][] G = new int[nMax][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < nMax; j++) {
                G[j][i] = -1;
            }
        }
        int z = n - 1;
        while (Q.size() > 1) {
            int x = Q.poll();
            int y = Q.poll();
            z++;
            fr[z] = fr[x] + fr[y];
            val[z] = Math.min(val[x], val[y]);
            Q.add(z);
            G[z][0] = x;
            G[z][1] = y;
        }
        String[] cod = new String[nMax];
        dfs(z, "", G, cod);
        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();
        fin.readLine();
        int c;
        while ((c = fin.read()) != -1) {
            s1.append((char) c);
            boolean ok = false;
            for (int j = 0; j < v.length && !ok; j++) {
                if (s2.toString().equals(cod[j])) {
                    fout.write(v[j]);
                    s2.setLength(0);
                    ok = true;
                }
            }
        }
        fin.close();
        fout.close();
    }
}
