// This code is contributed by @hkose1

// Time Complexity: O(n)
// Space Complexity: O(n)

import java.util.Arrays;
import java.util.List;

public class LinearSearch {
    public static void main(String[] args) {
        List<Integer> list = Arrays.asList(2, 56, 45, 13, 9, 0);

        int value1 = 13;
        int value2 = 299;

        int index1 = linearSearch(list, value1);  // Searching an existent value in the list
        System.out.println(index1);

        int index2 = linearSearch(list, value2);  // Searching an inexistent value in the list
        System.out.println(index2);
    }

    public static <T> int linearSearch(List<T> list, T target){
        for (int i = 0; i < list.size(); i++){
            if (list.get(i).equals(target)){
                return i;
            }
        }
        return -1;
    }
}
