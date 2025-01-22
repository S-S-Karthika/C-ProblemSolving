#include <iostream>
using namespace std;

#define SIZE 5

class Stack {
private:
    int topIndex;  // Renamed from 'top' to avoid conflict
    int arr[SIZE];

public:
    Stack() {
        topIndex = -1;
    }

    bool isEmpty() {
        return topIndex < 0;
    }

    bool isFull() {
        return topIndex == SIZE - 1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack overflow" << endl;
        } else {
            arr[++topIndex] = val;
            cout << val << " is pushed into the stack" << endl;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        int value = arr[topIndex--];
        cout << "The popped value is " << value << endl;
        return value;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty, so no top element" << endl;
            return -1;
        }

        cout << "The top value is " << arr[topIndex] << endl;
        return arr[topIndex];
    }
};

int main() {
    Stack s;
    cout << "Top element: " << s.top() << endl;
    s.push(10);      // Output: 10 is pushed into the stack
    cout << "Top element: " << s.top() << endl;
    s.push(20);      // Output: 20 is pushed into the stack
    cout << "Top element: " << s.top() << endl;
    s.pop();         // Output: The popped value is 20
    cout << "Top element: " << s.top() << endl;
    s.top();         // Output: The top value is 10

    return 0;
}
