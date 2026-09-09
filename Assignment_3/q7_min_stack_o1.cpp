#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<long long> s;
    long long minVal;

public:
    void push(long long x) {
        if (s.empty()) {
            s.push(x);
            minVal = x;
        } else if (x >= minVal) {
            s.push(x);
        } else {
            s.push(2 * x - minVal);
            minVal = x;
        }
    }

    void pop() {
        if (s.empty()) return;

        long long top = s.top();
        s.pop();

        if (top < minVal)
            minVal = 2 * minVal - top;
    }

    long long peek() {
        long long top = s.top();
        return (top < minVal) ? minVal : top;
    }

    long long getMin() {
        return minVal;
    }
};

int main() {
    MinStack s;

    s.push(2);
    s.push(3);
    cout << "Peek: " << s.peek() << endl;
    s.pop();
    cout << "getMin: " << s.getMin() << endl;
    s.push(1);
    cout << "getMin: " << s.getMin() << endl;

    return 0;
}
