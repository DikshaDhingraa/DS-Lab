#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int applyOperation(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return a / b;
}

int evaluatePostfix(const string &expr) {
    stack<int> s;
    string token;
    stringstream ss(expr);

    while (ss >> token) {
        if (isdigit(token[0]) ||
            (token.size() > 1 && token[0] == '-')) {
            s.push(stoi(token));
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            s.push(applyOperation(a, b, token[0]));
        }
    }
    return s.top();
}

int main() {
    string expr;
    cout << "Enter postfix expression (space separated): ";
    getline(cin, expr);

    cout << "Result: " << evaluatePostfix(expr) << endl;
    return 0;
}
