#include <iostream>
#include <stack>
using namespace std;

class QueueInStack {
private:
    stack<int> s1, s2;

public:
    // Push element to the back of the queue
    void push(int val) {
        s1.push(val);
    }

    // Remove the element from the front of the queue
    void pop() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    // Get the front element
    int top() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    // Check if the queue is empty
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    QueueInStack q;

    cout << "Top element: " << q.top() << endl; // Queue is empty
    q.push(10);
    cout << "Top element: " << q.top() << endl; // 10
    q.push(20);
    cout << "Top element: " << q.top() << endl; // 10
    q.push(30);

    cout << "Top element: " << q.top() << endl; // 10
    q.pop();
    cout << "Top element: " << q.top() << endl; // 20
    q.pop();
    cout << "Top element: " << q.top() << endl; // 30
    q.pop();
    cout << "Top element: " << q.top() << endl; // Queue is empty, -1

    return 0;
}
