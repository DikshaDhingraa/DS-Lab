#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(const string &str) {
    stack<char> s;
    for (char ch : str)
        s.push(ch);

    string result = "";
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
    return result;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Reversed string: " << reverseString(str) << endl;
    return 0;
}
