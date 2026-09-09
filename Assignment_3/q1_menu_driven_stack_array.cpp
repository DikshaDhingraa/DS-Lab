#include <iostream>
using namespace std;

const int MAX = 5;
int stackArr[MAX];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

void push(int value) {
    if (isFull())
        cout << "Stack Overflow" << endl;
    else
        stackArr[++top] = value;
}

void pop() {
    if (isEmpty())
        cout << "Stack Underflow" << endl;
    else
        cout << "Popped: " << stackArr[top--] << endl;
}

void peek() {
    if (isEmpty())
        cout << "Stack is empty" << endl;
    else
        cout << "Top element: " << stackArr[top] << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack (top to bottom): ";
    for (int i = top; i >= 0; i--)
        cout << stackArr[i] << " ";
    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n1. Push\n2. Pop\n3. isEmpty\n4. isFull";
        cout << "\n5. Display\n6. Peek\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;
            case 2: pop(); break;
            case 3:
                cout << (isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
                break;
            case 4:
                cout << (isFull() ? "Stack is full" : "Stack is not full") << endl;
                break;
            case 5: display(); break;
            case 6: peek(); break;
            case 7: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice" << endl;
        }
    } while (choice != 7);

    return 0;
}
