// This code is contributed by Riyazul555

// Time complexity  = O(N log N)   N is number of unique characters
// Space complexity = O(N)         N is number of unique characters



import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class HuffmanCoding {
    static final int nMax = 20005;

    static void dfs(int nod, String val, int[][] G, String[] cod) {
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
        Map<Character, Integer> ap = new HashMap<>();
        String s = fin.readLine();
        char[] charArray = s.toCharArray();
        for (char c : charArray) {
            ap.put(c, ap.getOrDefault(c, 0) + 1);
        }
        StringBuilder v = new StringBuilder();
        for (char c : charArray) {
            if (v.indexOf(Character.toString(c)) == -1)
                v.append(c);
        }
        v.sort(null);
        int[] val = new int[nMax];
        int[] fr = new int[nMax];
        for (int i = 0; i < v.length(); i++) {
            fout.write(v.charAt(i) + " " + ap.get(v.charAt(i)) + "\n");
            fr[i] = ap.get(v.charAt(i));
            val[i] = i;
        }
        Comparator<Integer> compare = (a, b) -> ((fr[a] > fr[b]) || (fr[a] == fr[b] && val[a] > val[b])) ? 1 : -1;
        PriorityQueue<Integer> Q = new PriorityQueue<>(compare);
        for (int i = 0; i < v.length(); i++)
            Q.add(i);
        int[][] G = new int[nMax][2];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < nMax; j++)
                G[j][i] = -1;
        int z = v.length() - 1;
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
        Map<Character, String> codif = new HashMap<>();
        for (int i = 0; i < v.length(); i++)
            codif.put(v.charAt(i), cod[i]);
        for (char c : charArray)
            fout.write(codif.get(c));
        fin.close();
        fout.close();
    }
}
