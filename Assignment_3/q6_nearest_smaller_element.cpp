#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nearestSmaller(const vector<int> &a) {
    vector<int> ans;
    stack<int> s;

    for (int x : a) {
        while (!s.empty() && s.top() >= x)
            s.pop();

        ans.push_back(s.empty() ? -1 : s.top());
        s.push(x);
    }
    return ans;
}

int main() {
    vector<int> a = {4, 5, 2, 10, 8};
    vector<int> ans = nearestSmaller(a);

    cout << "Nearest smaller elements: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
