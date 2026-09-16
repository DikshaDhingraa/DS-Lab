// Additional Q4: Number of Students Unable to Eat Lunch
// Students queue up, sandwiches are in a stack (front = top).
// If the front student's preference matches the top sandwich, they take it and leave.
// Otherwise, they go to the back of the queue.
// This stops once no remaining student wants the top sandwich.
// Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
// Output: 0

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countStudents(vector<int> &students, vector<int> &sandwiches) {
    queue<int> q;
    for (int s : students) q.push(s);

    int idx = 0;              // index into sandwiches (acts like top of stack)
    int rotations = 0;        // consecutive students who refused the top sandwich
    int n = q.size();

    while (!q.empty() && rotations < (int)q.size()) {
        if (q.front() == sandwiches[idx]) {
            // student takes the sandwich
            q.pop();
            idx++;
            rotations = 0;     // reset, progress was made
        } else {
            // student goes to the back of the queue
            q.push(q.front());
            q.pop();
            rotations++;
        }
    }

    return q.size();
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> students(n), sandwiches(n);

    cout << "Enter student preferences (0 = circular, 1 = square): ";
    for (int i = 0; i < n; i++) cin >> students[i];

    cout << "Enter sandwich stack, top first (0 = circular, 1 = square): ";
    for (int i = 0; i < n; i++) cin >> sandwiches[i];

    cout << "Students unable to eat: " << countStudents(students, sandwiches) << endl;

    return 0;
}
