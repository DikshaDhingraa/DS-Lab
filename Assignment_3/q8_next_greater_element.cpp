#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreater(const vector<int> &a) {
    int n = a.size();
    vector<int> ans(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= a[i])
            s.pop();

        if (!s.empty())
            ans[i] = s.top();

        s.push(a[i]);
    }
    return ans;
}

int main() {
    vector<int> a = {1, 3, 2, 4};
    vector<int> ans = nextGreater(a);

    cout << "Next greater elements: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
