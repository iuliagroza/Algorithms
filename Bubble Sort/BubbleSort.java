// This code is contributed by @hkose1

// Time Complexity: O(n^2)
// Space Complexity: O(n)

import java.util.Arrays;
import java.util.List;

public class BubbleSort {
    public static void main(String[] args) {
        List<Integer> list = Arrays.asList(2, 56, 45, 13, 9, 0);

        System.out.print("Before sorting: ");
        System.out.println(list);

        System.out.print("After sorting using bubble sort: ");
        bubbleSort(list);
        System.out.println(list);
    }

    public static <T extends Comparable<T>> void bubbleSort(List<T> list){
        if (list == null)
            return;
        int len = list.size();
        for (int i = 0; i < len; i++){
            for (int j = 0; j < len - 1 - i; j++){
                if (list.get(j).compareTo(list.get(j + 1)) > 0){
                    T temp = list.get(j);
                    list.set(j,list.get(j+1));
                    list.set(j + 1, temp);
                }
            }
        }
    }
}
