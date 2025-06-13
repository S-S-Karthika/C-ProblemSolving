#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    
    Node(int data) {
        val = data;
        next = nullptr;
    }
};

class Stack {
private:
    Node* topnode;

public:
    Stack() {
        topnode = nullptr;
    }

    bool isEmpty() {
        return topnode == nullptr;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = topnode;
        topnode = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = topnode;
        topnode = topnode->next;
        delete temp;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1;
        }
        return topnode->val;
    }

    void display() {
        Node* curr = topnode;
        cout << "Stack (top to bottom): ";
        while (curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    st.display(); // 30 20 10

    cout << "Top element: " << st.top() << endl;

    st.pop();
    cout << "After popping:" << endl;
    st.display(); // 20 10

    return 0;
}
