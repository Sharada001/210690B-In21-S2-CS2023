#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int left = 2*root+1;
   int right = 2*root+2;
   int max;
   if (left < n && arr[left] > arr[root]) {
      max = left;
   } else {
      max = root;
   }
   if (right < n && arr[right] > arr[max]) {
      max = right;
   }
   if (max != root) {
      swap(arr[root], arr[max]);
      heapify(arr, n, max);
   }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   
   
   // extracting elements from heap one by one
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}