#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(const vector<int> &t) {
    int n = t.size();
    vector<int> ans(n, 0);
    stack<int> s; // stores indices

    for (int i = 0; i < n; i++) {
        while (!s.empty() && t[i] > t[s.top()]) {
            int j = s.top();
            s.pop();
            ans[j] = i - j;
        }
        s.push(i);
    }
    return ans;
}

int main() {
    vector<int> t = {73,74,75,71,69,72,76,73};
    vector<int> ans = dailyTemperatures(t);

    cout << "Waiting days: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
