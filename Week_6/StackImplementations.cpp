#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

// function to swap two elements in the array
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// function to partition the array and return the index of the pivot element
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // pivot element
    int i = (low - 1); // index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // if current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);

        }
    }
    swap(&arr[i + 1], &arr[high]); // swap arr[i+1] and arr[high]

    return (i + 1);
}

// function to perform quicksort
void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // find pivot element and partition the array
        int pi = partition(arr, low, high);

        // recursively sort the left and right subarrays
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

/*
void iterative_quicksort(vector<int>& arr, int low, int high) {
    // create an empty stack
    stack<int> s;

    // push initial values of low and high to the stack
    s.push(low);
    s.push(high);

    // loop until stack is empty
    while (!s.empty()) {
        // pop high and low values from the stack
        high = s.top();
        s.pop();
        low = s.top();
        s.pop();

        // partition the array and get the pivot element index
        int pi = partition(arr, low, high);

        // if there are elements on the left of the pivot, push them to the stack
        if (pi - 1 > low) {
            s.push(low);
            s.push(pi - 1);
        }

        // if there are elements on the right of the pivot, push them to the stack
        if (pi + 1 < high) {
            s.push(pi + 1);
            s.push(high);
        }
    }
}
*/

void iterative_quicksort(vector<int> arr, int n) {
    stack<int> s;
    int low = 0, high = n - 1;
    s.push(low);
    s.push(high);

    while (!s.empty()) {
        high = s.top();
        s.pop();
        low = s.top();
        s.pop();

        int pivot = arr[(low + high) / 2];
        int i = low, j = high;

        while (i <= j) {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (low < j) {
            s.push(low);
            s.push(j);
        }
        if (i < high) {
            s.push(i);
            s.push(high);
        }
    }
}


vector<int> random_vector(int n) {
    vector<int> v(n);
    srand(time(0)); // seed the random number generator with the current time
    for (int i = 0; i < n; i++) {
        v[i] = rand(); // generate a random integer and add it to the vector
    }
    return v;
}

// main function to test the quicksort algorithm
int main() {

    for (int n=5000; n<100000; n = n*2) {
        vector<int> arr1 = random_vector(n);
        cout << "input array size" << n<< endl;

        auto start_time = std::chrono::high_resolution_clock::now();
        quicksort(arr1,0,n-1);
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
        std::cout << "Execution time: " << duration.count() << " microseconds\n"<<endl;


        auto start_time2 = std::chrono::high_resolution_clock::now();
        iterative_quicksort(arr1,n);
        auto end_time2 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end_time2 - start_time2);
        std::cout << "Execution time: " << duration2.count() << " microseconds\n"<<endl;
        cout<< endl;
    }


    return 0;

}

