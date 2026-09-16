// Additional Q3: Given a Queue of first n natural numbers (random order), check whether
// it can be arranged in increasing order in another queue using a stack.
// Allowed operations: push/pop stack, dequeue from given queue, enqueue into another queue.
// Input : Queue[] = {5, 1, 2, 3, 4}
// Output: Yes

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkSorted(int n, queue<int> &q) {
    stack<int> st;
    int expected = 1;

    while (!q.empty()) {
        int front = q.front();

        if (front == expected) {
            // the expected element is at the front of the queue, remove it
            q.pop();
            expected++;
        } else if (!st.empty() && st.top() == expected) {
            // the expected element is on top of the stack
            st.pop();
            expected++;
        } else if (st.empty() || st.top() > front) {
            // push current front element onto stack (it might be needed later)
            st.push(front);
            q.pop();
        } else {
            // neither queue front nor stack top matches expected, and
            // pushing won't help -> cannot be sorted
            break;
        }
    }

    // drain any remaining matching elements from the stack
    while (!st.empty() && st.top() == expected) {
        st.pop();
        expected++;
    }

    return q.empty() && st.empty();
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    queue<int> q;
    cout << "Enter " << n << " elements (a permutation of 1 to n): ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    cout << (checkSorted(n, q) ? "Yes" : "No") << endl;

    return 0;
}
