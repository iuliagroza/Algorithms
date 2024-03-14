// This code is contributed by Riyazul555

// Time Complexity  =  O(N)  N is number of nodes in the tree
// Space Complexity = O(N)  N is number of nodes in the tree

import java.io.*;
import java.util.*;

public class Main {
    static final int nMax = 100005;

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader(args[0]));
        BufferedWriter fout = new BufferedWriter(new FileWriter(args[1]));

        int n = Integer.parseInt(fin.readLine());
        int[] daddy = new int[nMax];
        int[] deg = new int[nMax];

        StringTokenizer st = new StringTokenizer(fin.readLine());
        for (int i = 0; i < n; i++) {
            daddy[i] = Integer.parseInt(st.nextToken());
            deg[i]++;
            deg[daddy[i]]++;
        }

        int ptr = -1;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1 && ptr == -1) {
                ptr = i;
            }
        }

        List<Integer> sol = new ArrayList<>();
        int leaf = ptr;
        for (int i = 0; i < n - 1; i++) {
            int nxt = daddy[leaf];
            sol.add(nxt);
            if (--deg[nxt] == 1 && nxt < ptr) {
                leaf = nxt;
            } else {
                ptr++;
                while (deg[ptr] != 1) {
                    ptr++;
                }
                leaf = ptr;
            }
        }

        fout.write((n - 1) + "\n");
        for (int i : sol) {
            fout.write(i + " ");
        }

        fin.close();
        fout.close();
    }
}
