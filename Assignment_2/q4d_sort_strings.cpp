#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int n;
 
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();   // consume leftover newline left by cin >> n
 
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, words[i]);
    }
 
    // std::sort uses string's own < operator, which compares
    // strings alphabetically (lexicographically)
    sort(words.begin(), words.end());
 
    cout << "Strings in alphabetical order:" << endl;
    for (const string &w : words)
        cout << w << endl;
 
    return 0;
}
