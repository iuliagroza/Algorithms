// This code is contributed by Riyazul555

// Time Complexity  = O(V²*logv + VE)    where where V is the number of vertices and E is the number of edges
// Space Complexity = O(V²)              where where V is the number of vertices and E is the number of edges

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {
    static final int nMax = 1005;
    static final int INF = 1_000_000_000;

    static class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static void bf(int nod, int n, int[] h, ArrayList<Pair>[] G, boolean[] ok) {
        Queue<Integer> Q = new PriorityQueue<>();
        boolean[] in = new boolean[nMax];
        int[] nr = new int[nMax];
        Arrays.fill(h, INF);
        h[nod] = 0;
        Q.add(nod);
        in[nod] = true;
        while (!Q.isEmpty()) {
            nod = Q.poll();
            in[nod] = false;
            for (Pair i : G[nod]) {
                if (h[nod] + i.second < h[i.first]) {
                    h[i.first] = h[nod] + i.second;
                    nr[i.first]++;
                    if (nr[i.first] > n) {
                        ok[0] = true;
                        return;
                    }
                    if (!in[i.first]) {
                        in[i.first] = true;
                        Q.add(i.first);
                    }
                }
            }
        }
    }

    static void dijkstra(int nod, int n, int[] d, ArrayList<Pair>[] G) {
        PriorityQueue<Pair> Q = new PriorityQueue<>((a, b) -> Integer.compare(b.second, a.second));
        boolean[] in = new boolean[nMax];
        Q.add(new Pair(0, nod));
        Arrays.fill(d, -INF);
        d[nod] = 0;
        while (!Q.isEmpty()) {
            if (!in[Q.peek().first]) {
                int x = Q.poll().first;
                for (Pair i : G[x]) {
                    if (d[x] - i.second > d[i.first]) {
                        Q.add(new Pair(i.first, d[x] - i.second));
                        d[i.first] = d[x] - i.second;
                    }
                }
                in[x] = true;
            } else {
                Q.poll();
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader(args[0]));
        BufferedWriter fout = new BufferedWriter(new FileWriter(args[1]));
        String[] line = fin.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        ArrayList<Pair>[] G = new ArrayList[nMax];
        for (int i = 0; i < nMax; i++) {
            G[i] = new ArrayList<>();
        }
        while (m-- > 0) {
            line = fin.readLine().split(" ");
            int x = Integer.parseInt(line[0]);
            int y = Integer.parseInt(line[1]);
            int w = Integer.parseInt(line[2]);
            G[x].add(new Pair(y, w));
        }
        int s = n;
        for (int i = 0; i < n; i++) {
            G[s].add(new Pair(i, 0));
        }
        int[] h = new int[nMax];
        boolean[] ok = new boolean[1];
        bf(s, n, h, G, ok);
        if (ok[0]) {
            fout.write("-1");
        } else {
            for (int i = 0; i < n; i++) {
                for (Pair j : G[i]) {
                    j.second += h[i] - h[j.first];
                    fout.write(i + " " + j.first + " " + j.second + "\n");
                }
            }
            int[] d = new int[nMax];
            for (int i = 0; i < n; i++) {
                dijkstra(i, n, d, G);
                for (int j = 0; j < n; j++) {
                    if (i == j) {
                        fout.write("0 ");
                    } else if (d[j] == -INF) {
                        fout.write("INF ");
                    } else {
                        fout.write(-d[j] - h[i] + h[j] + " ");
                    }
                }
                fout.write("\n");
            }
        }
        fin.close();
        fout.close();
    }
}
