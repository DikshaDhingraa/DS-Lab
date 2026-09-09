#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
 
int countDistinct(const vector<int> &arr) {
    // Inserting every element into a set automatically drops
    // duplicates, so the set's final size is the distinct count
    unordered_set<int> seen;
    for (int x : arr)
        seen.insert(x);
    return seen.size(); }
int main() {
    vector<int> arr = {10, 20, 20, 10, 30, 40, 30};
    cout << "Number of distinct elements: " << countDistinct(arr) << endl;
    return 0;}
