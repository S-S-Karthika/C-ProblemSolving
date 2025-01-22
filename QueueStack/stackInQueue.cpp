#include <iostream>
#include <queue>
using namespace std;

class stackInQueue {
private:
    queue<int> q1, q2;

public:
    void push(int val) {
        // Push element to q2
        q2.push(val);

        // Transfer elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2 to maintain the stack order
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    stackInQueue s;
    
    
    cout << "Top element: " << s.top() << endl;
    s.push(10);
    cout << "Top element: " << s.top() << endl;
    s.push(20);
    cout << "Top element: " << s.top() << endl;
    s.push(30);
    
    cout << "Top element: " << s.top() << endl; // 30
    s.pop();
    cout << "Top element: " << s.top() << endl; // 20
    s.pop();
    cout << "Top element: " << s.top() << endl; // 10
    s.pop();
    cout << "Top element: " << s.top() << endl; //-1

    return 0;
}
