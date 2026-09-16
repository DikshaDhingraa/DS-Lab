// Q4: Find first non-repeating character in a stream of characters using Queue
// Sample I/P: a a b c
// Sample O/P: a -1 b b

#include <iostream>
#include <queue>
using namespace std;

int main() {
    string input;
    cout << "Enter characters separated by spaces (e.g. a a b c): ";
    getline(cin, input);

    queue<char> q;
    int count[256] = {0};

    cout << "Output: ";
    for (char ch : input) {
        if (ch == ' ') continue;

        count[(unsigned char)ch]++;
        q.push(ch);

        // remove characters from front that are now repeating
        while (!q.empty() && count[(unsigned char)q.front()] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
    cout << endl;

    return 0;
}
