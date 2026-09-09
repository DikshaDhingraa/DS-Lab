#include <iostream>
#include <vector>
using namespace std;
 
// Merges two sorted halves and counts how many elements crossed
// over out of order (these are the "split" inversions)
int mergeCount(vector<int> &arr, vector<int> &temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int invCount = 0;
 
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // arr[i] > arr[j]: arr[j] is smaller than every
            // remaining element in the left half, so all of
            // them form an inversion with arr[j]
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }
    while (i <= mid)   temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
 
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return invCount;
}
 
// Standard merge sort, accumulating the inversion count
int mergeSortCount(vector<int> &arr, vector<int> &temp, int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        invCount += mergeSortCount(arr, temp, left, mid);
        invCount += mergeSortCount(arr, temp, mid + 1, right);
        invCount += mergeCount(arr, temp, left, mid, right);
    }
    return invCount;
}
 
int main() {
    vector<int> arr = {8, 4, 2, 1};
    vector<int> temp(arr.size());
 
    int result = mergeSortCount(arr, temp, 0, arr.size() - 1);
    cout << "Number of inversions: " << result << endl;
 
    return 0;
}
