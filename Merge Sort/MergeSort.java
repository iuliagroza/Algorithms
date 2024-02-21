// This code is contributed by @hkose1

// Time Complexity: O(n*log2(n))
// Additional Space: O(n)

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


public class MergeSort {
    public static void main(String[] args) {
        
        List<Integer> integers = Arrays.asList(2, 56, 45, 13, 9, 0);
        System.out.println("Before sorting: " + integers);
        mergeSort(integers);
        System.out.println("After sorting: " + integers);

        System.out.println();
        
        List<String> strings = Arrays.asList("bca","cba","abc");
        System.out.println("before sorting: " + strings);
        mergeSort(strings);
        System.out.println("after sorting: "+ strings);

        
    
    }


    public static <T extends Comparable<T>> void mergeSort(List<T> list) {
        if (list == null)
            return;

        if (list.size() > 1) {
            int mid = list.size()/2;
            
            List<T> left = new ArrayList<>();
            for(int i = 0; i < mid; i++)
                left.add(list.get(i));
            mergeSort(left);

    
            List<T> right = new ArrayList<>();
            for(int i = mid; i < list.size(); i++)
                right.add(list.get(i));
            mergeSort(right);

            merge(left, right, list);
            
        }   

    }

    public static <T extends Comparable<T>> void merge(List<T> left, List<T> right, List<T> temp) {
        int currentLeft = 0;
        int currentRight = 0;
        int currentTemp = 0;
        
        while (currentLeft < left.size() && currentRight < right.size()) {

            if (left.get(currentLeft).compareTo(right.get(currentRight)) < 0) {
                
                temp.set(currentTemp++, left.get(currentLeft++));

            } else {
                
                temp.set(currentTemp++, right.get(currentRight++));
            }
            
        }

        while (currentLeft < left.size()) {
            temp.set(currentTemp++, left.get(currentLeft++));
           
        }
        while (currentRight < right.size()) {
            temp.set(currentTemp++, right.get(currentRight++));
        }   

    }



}

