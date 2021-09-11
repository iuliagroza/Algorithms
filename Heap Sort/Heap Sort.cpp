/// This code is contributed by @notreallystatic

/// Time Complexity: O(nlogn)
/// Space Complexity: O(1) (Arrange the array into a heap, in place.)

// Using vectors to represent an array.
#include <iostream>
#include <vector>

using namespace std;

int left(const int &i)
{
  return (2*i+1);
}

int right(const int &i)
{
  return (2*i+2);
}

void heapify(vector<int> &arr, const int &i, const int &n)
{
  int l=left(i);
  int r=right(i);
  int largest=i;
  if(l<n && arr[l]>arr[i])
    largest=l;
  if(r<n && arr[r]>arr[largest])
    largest=r;
  if(largest!=i)
  {
    swap(arr[largest], arr[i]);
    heapify(arr, largest, n);
  }
}

void heapSort(vector<int> &arr)
{
  int n=arr.size();

  for(int i=n/2-1; i>=0; i--) {
    heapify(arr, i, n);
  }

  for(int i=n-1; i>=0; i--) {
    swap(arr[i], arr[0]);
    heapify(arr, 0, i);
  }
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NUll);

  vector<int> arr = {0, 3, 10, -2, 20, 19, 2};

  heapSort(arr);

  for(int x : arr){
    cout << x << " ";
  }

  return 0;
}
