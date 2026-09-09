#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string removeVowels(const string &str) {
    string result = "";
    for (char ch : str) {
        char lower = tolower(ch);
        if (lower != 'a' && lower != 'e' && lower != 'i' && lower != 'o' && lower != 'u') {
            result += ch;   // keep only non-vowel characters
        }  }
    return result; }
int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "String after removing vowels: " << removeVowels(str) << endl;
    return 0;}
