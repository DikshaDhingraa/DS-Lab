#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool canBeSorted(const vector<int> &A) {
    vector<int> target = A;
    sort(target.begin(), target.end());

    stack<int> s;
    int j = 0;

    for (int x : A) {
        s.push(x);

        while (!s.empty() && j < (int)target.size() &&
               s.top() == target[j]) {
            s.pop();
            j++;
        }
    }

    return j == (int)target.size();
}

int main() {
    vector<int> A1 = {2, 4, 1243, 4, 1342};
    vector<int> A2 = {2, 1, 3};

    cout << "A1: " << (canBeSorted(A1) ? "Yes" : "No") << endl;
    cout << "A2: " << (canBeSorted(A2) ? "Yes" : "No") << endl;

    return 0;
}
