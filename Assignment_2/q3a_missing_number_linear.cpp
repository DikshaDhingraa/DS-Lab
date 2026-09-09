#include <iostream>
using namespace std;
 
// Array holds n-1 distinct integers from the range 1..n (one is missing)
int findMissingLinear(int arr[], int n) {
    int expectedSum = (n + 1) * (n + 2) / 2;
    int actualSum = 0;
    for (int i = 0; i < n; i++)
        actualSum += arr[i];
    return expectedSum - actualSum;
}
 
int main() {
    int arr[] = {1, 2, 3, 5, 6, 7, 8}; // 4 is missing, range is 1 to 8
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Missing number (Linear method): " << findMissingLinear(arr, n) << endl;
 
    return 0;
}
