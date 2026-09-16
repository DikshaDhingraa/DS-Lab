// Additional Q2: Sort a queue without using extra space (extra data structures)
// Allowed operations: enqueue(), dequeue(), isEmpty()
// Uses recursion (the call stack) instead of an explicit extra structure
// Input: 11 5 4 21
// Output: 4 5 11 21

#include <iostream>
#include <queue>
using namespace std;

// Inserts x into an already-sorted queue (ascending, front to back) of size n,
// keeping it sorted, using only front(), pop(), push().
// Idea: rotate the "<= x" elements to the back, push x, then rotate the
// remaining "> x" elements (now at the front) to the back as well.
void sortedInsert(queue<int> &q, int x, int n) {
    int count = 0;
    while (count < n && q.front() <= x) {
        q.push(q.front());
        q.pop();
        count++;
    }

    q.push(x);

    // rotate the remaining (originally ">x") elements from front to back
    for (int i = 0; i < n - count; i++) {
        q.push(q.front());
        q.pop();
    }
}

void sortQueue(queue<int> &q) {
    if (q.empty()) return;

    int x = q.front();
    q.pop();
    int remainingSize = q.size();

    sortQueue(q);

    sortedInsert(q, x, remainingSize);
}

int main() {
    queue<int> q;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    sortQueue(q);

    cout << "Sorted queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
