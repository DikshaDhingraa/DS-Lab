#include <iostream>
#include <string>
using namespace std;
 
void reverseString(string &str) {
    int start = 0, end = str.length() - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
 
int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    reverseString(str);
    cout << "Reversed string: " << str << endl;
    return 0;
}
