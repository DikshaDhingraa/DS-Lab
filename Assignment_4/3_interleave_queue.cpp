// Q3: Interleave the first half of the queue with the second half
// Sample I/P: 4 7 11 20 5 9
// Sample O/P: 4 20 7 5 11 9

#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int> &q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even to interleave." << endl;
        return;
    }

    queue<int> firstHalf, secondHalf;
    int half = n / 2;

    // split into two halves
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }
    for (int i = 0; i < half; i++) {
        secondHalf.push(q.front());
        q.pop();
    }

    // interleave: one element from first half, one from second half
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(secondHalf.front());
        secondHalf.pop();
    }
}

int main() {
    queue<int> q;
    int n;

    cout << "Enter number of elements (even number): ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    interleaveQueue(q);

    cout << "Interleaved queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
