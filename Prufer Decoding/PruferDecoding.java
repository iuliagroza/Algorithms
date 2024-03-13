// This code is contributed by Riyazul555

// Time Complexity = O(N)  where N is number of elements in input array 
// Space Complexity = O(N) where N is number of elements in input array


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        try {
            BufferedReader fin = new BufferedReader(new FileReader(args[0]));
            BufferedWriter fout = new BufferedWriter(new FileWriter(args[1]));

            int n = Integer.parseInt(fin.readLine());
            int[] cod = new int[n];
            int[] deg = new int[n + 5];
            Arrays.fill(deg, 0);

            String[] tokens = fin.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                cod[i] = Integer.parseInt(tokens[i]);
                deg[cod[i]]++;
            }

            int ptr = 0;
            while (deg[ptr] != 0)
                ptr++;

            int leaf = ptr;
            int[] p = new int[n + 5];
            Arrays.fill(p, -1);

            for (int i = 0; i < n; i++) {
                p[leaf] = cod[i];
                if (--deg[cod[i]] == 0 && cod[i] < ptr)
                    leaf = cod[i];
                else {
                    ptr++;
                    while (deg[ptr] != 0)
                        ptr++;
                    leaf = ptr;
                }
            }

            fout.write((n + 1) + "\n");
            for (int i = 0; i < n + 1; i++)
                fout.write(p[i] + " ");

            fin.close();
            fout.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
