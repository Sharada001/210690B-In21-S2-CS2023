#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

double returnMedian(vector<int> arr){
    int length = arr.size();
    double median;
    if (length%2==0){
        int midLeftIndex = length/2 -1;
        median = ((double)arr[midLeftIndex] + (double)arr[midLeftIndex+1])/(double)2;
    }
    else{
        int midLeftIndex = length/2 ;
        median = arr[midLeftIndex];
    }
    return median;
}

void sortAsStream(vector<int>& vec) {
    int n = vec.size();
    vector<int> vecToSort;
    for(int i=0;i<n;i++){
        for(int j=0; j<=i; j++){
            vecToSort.push_back(vec[j]);
        }
        insertionSort(vecToSort);
        for(int j=0; j<=i; j++){
            cout << vecToSort[j]<< ' ';
        }
        double median = returnMedian(vecToSort);
        cout<<'\t'<< "Median is : " << median;
        cout<< endl;
        vecToSort = {};
    }
}

int main() {
    vector<int> vec = { 7, 3, 5, 2, 5, 8, 4, 3, 10, 2, 6, 11, 1, 2 };
    sortAsStream(vec);
    return 0;
}

