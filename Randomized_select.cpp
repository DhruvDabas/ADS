#include <iostream>
#include <vector>
#include <cstdlib>  // for rand and srand
#include <ctime>    // for time
using namespace std;
int randomizedPartition(vector<int>& arr, int start, int end) {
    int pivotIndex = start + rand() % (end - start + 1);
    
    swap(arr[pivotIndex], arr[end]);
    
    int pivot = arr[end];
    int i = start - 1;
    
    for (int j = start; j < end; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

int randomizedSelect(vector<int>& arr, int start, int end, int k) {
    if (start == end) {
        return arr[start];
    }
    
    int pivotIndex = randomizedPartition(arr, start, end);
    int pivotRank = pivotIndex - start + 1;
    
    if (k == pivotRank) {
        return arr[pivotIndex];
    } 
    else if (k < pivotRank) {
        return randomizedSelect(arr, start, pivotIndex - 1, k);
    } 
    else {
        return randomizedSelect(arr, pivotIndex + 1, end, k - pivotRank);
    }
}

int main() {
    srand(time(0));
    
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    
    if (k > 0 && k <= arr.size()) {
        int result = randomizedSelect(arr, 0, arr.size() - 1, k);
        cout << "The " << k << "-th smallest element is " << result << endl;
    } 
    else {
        cout << "Invalid value of k" << endl;
    }

}