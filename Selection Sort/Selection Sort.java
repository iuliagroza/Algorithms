// This code is contribuited by @Abbeyme1

public class SelectionSort  {

    public static void sort(int[] arr) {
        int n = arr.length;
        for(int i=0;i<n-1;i++)
        {
            int minIndex = i; //pointer to store index of current val
            for(int j=i+1;j<n;j++)
            {
                if(arr[minIndex] > arr[j]) // if we found a lesser value than our current pointer value then we will store that index value to our minIndex variable
                {
                    minIndex = j; // storing the index in minIndex variable
                }
            }

            //swapping the minimum element with the pointer element
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;

        }
    }

    public static void print(int[] arr) {
        for(int i=0;i<arr.length;i++)
        {
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String[] args) {
        int arr[] = {5,12,9,3,1,6};
        sort(arr);
        print(arr);

    }
}