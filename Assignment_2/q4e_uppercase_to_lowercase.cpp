#include <iostream>
using namespace std;
int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;
    if (ch >= 'A' && ch <= 'Z') {
        char lower = ch + 32;   // shift by 32 in the ASCII table
        cout << "Lowercase character: " << lower << endl;
    } else {
        cout << "Entered character is not an uppercase letter." << endl;
    }
    return 0;
}
