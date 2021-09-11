// This code is contributed by @Abbeyme1

public class InsertionSort {
    public static void main(String[] args) {
        int arr[] = {9, 6, 11, 2, 1};
        insertionSort(arr);
        print(arr);
    }

    public static void insertionSort(int[] arr) {
        int n = arr.length;
        for(int i=1; i<n; i++)
        {
            // Storing value in a variable "val"
            int val = arr[i];
            // Starting pointer from a previous value
            int j = i-1;

            // Checking and swapping till our stored value in (val) is lesser than the pointer val
            while (j >= 0 && arr[j] > val)
            {
                // Shifting val ahead
                arr[j+1] = arr[j];
                j = j - 1;
            }
            // j+1 is used as our pointer will step backward due to while loop
            arr[j+1] = val;
        }
    }


    // print array
    public static void print(int[] arr) {
        for(int i=0; i<arr.length; i++)
        {
            System.out.print(arr[i]+ " ");
        }
    }