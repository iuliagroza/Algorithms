// This code is contributed by @hkose1

// Time complexity: O(log n)

import java.util.ArrayList;

public class BinarySearch {
    public static void main(String[] args) {
        // Inorder to use binary search the list that we passed to the method must be sorted
        Integer[] integers = {1, 4, 12, 23, 30, 45, 56, 87, 100};
        ArrayList<Integer> integerList = new ArrayList<>();
        for(Integer integer : integers)
            integerList.add(integer);
        
        System.out.println(binarySearch(integerList, 0, integerList.size(), 4)); 
        System.out.println(binarySearch(integerList, 0, integerList.size(), 100)); 
        System.out.println(binarySearch(integerList, 0, integerList.size(), 25));

    }

    // iterative solution of binary search
    public static <T extends Comparable<T>> int binarySearch(ArrayList<T> list, int low, int high, T target){
        if (list != null){
            while (low <= high){
                int mid = (low + high) / 2;
                if (list.get(mid).compareTo(target) == 0){  // target is found
                    return mid;
                }
                else if (list.get(mid).compareTo(target) > 0){  // search the left of the list
                    high = mid - 1;
                }
                else{  // search the right of the list
                    low = mid + 1;
                }
            }
        }
        return -1;  // not found
    }

    // recursive solution of binary search
    public static <T extends Comparable<T>> int binarySearchWithRecursive(ArrayList<T> list, int low, int high, T target){
        if (list == null){ return -1; }
        if (low <= high){
            int mid = (low + high) / 2;
            if (list.get(mid).compareTo(target) == 0){  // target is found
                return mid;
            }
            else if (list.get(mid).compareTo(target) > 0){  // search left part of the list
                return binarySearch(list, low, mid-1, target);
            }
            else{
                return binarySearch(list, mid+1, high, target);  // search right part of the list
            }
        }else{
            return -1;  // not found
        }
    }
}