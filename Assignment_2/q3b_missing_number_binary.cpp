#include <iostream>
using namespace std;
 
// arr is sorted and holds n-1 distinct integers from range 1..n
int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // If value equals its expected value (index+1), nothing
        // missing so far -> search the right half
        if (arr[mid] == mid + 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    // The missing number is low + 1
    return low + 1;
}
 
int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8}; // 5 is missing, range is 1 to 8
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Missing number (Binary Search method): " << findMissingBinary(arr, n) << endl;
 
    return 0;
}
