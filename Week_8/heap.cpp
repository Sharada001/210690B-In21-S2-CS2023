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
   for (int i = n/2-1; i >= 0; i--) {
      heapify(arr, n, i);
   }
   // extracting elements from heap one by one
   for (int i = n-1; i >= 0; i--) {
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
   }
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
   // int heap_arr[] = {10,13,12,20,13};
   // int heap_arr[] = {3,12,7,20,2,1,7,13,16,18,5,6};
   // int heap_arr[] = {5,17,16,18,2,1,8,16,11,18,5,6,12,15,4,2,14,9,6};
   // int heap_arr[] = {4,17,11,20,2,1,8,16,13,18,5,6,19,15,4,3,12,9,6,2,0,5,18,14,10};
   int n;
   cout<<"Enter Number Of Elements :"<<endl;
   cin>>n;
   cout<<"Enter Array Elements :"<<endl;
   int heap_arr[n];
   for (int i =0;i<n;i++){
        cin>>heap_arr[i];
   }
   // int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout << endl;
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
   cout << endl;
}