// This code is contributed by Riyazul555

// Time Complexity  =  O(V + E)  
// Space Complexity =  O(V + E)  

import java.io.*;
import java.util.*;

public class EulerPath {

    static void euler(int nod, ArrayList<Pair<Integer, Integer>>[] G, ArrayList<Integer> e, BitSet viz) {
        while (!G[nod].isEmpty()) {
            Pair<Integer, Integer> it = G[nod].remove(G[nod].size() - 1);
            if (!viz.get(it.second)) {
                viz.set(it.second);
                euler(it.first, G, e, viz);
            }
        }
        e.add(nod);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader(args[0]));
        BufferedWriter fout = new BufferedWriter(new FileWriter(args[1]));

        StringTokenizer st = new StringTokenizer(fin.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        ArrayList<Pair<Integer, Integer>>[] G = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            G[i] = new ArrayList<>();
        }

        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(fin.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            G[x].add(new Pair<>(y, i));
            G[y].add(new Pair<>(x, i));
        }

        ArrayList<Integer> e = new ArrayList<>();
        BitSet viz = new BitSet(m);
        euler(1, G, e, viz);

        for (int i = e.size() - 1; i > 0; i--) {
            fout.write(e.get(i) + " ");
        }

        fin.close();
        fout.close();
    }

    static class Pair<A, B> {
        A first;
        B second;

        public Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }
    }
}
