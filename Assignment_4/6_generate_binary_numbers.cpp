// Additional Q1: Generate and print all binary numbers with decimal values from 1 to n
// Input: n = 2
// Output: 1, 10

#include <iostream>
#include <queue>
using namespace std;

void generateBinaryNumbers(int n) {
    queue<string> q;
    q.push("1");

    for (int i = 1; i <= n; i++) {
        string curr = q.front();
        q.pop();

        cout << curr;
        if (i != n) cout << ", ";

        q.push(curr + "0");
        q.push(curr + "1");
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Output: ";
    generateBinaryNumbers(n);

    return 0;
}
