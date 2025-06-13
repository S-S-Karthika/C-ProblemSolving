#include <iostream>
#include <stack>
using namespace std;

// Insert an element at the bottom of the stack
void insertAtBottom(stack<int> &st, int val) {
    if (st.empty()) {
        st.push(val);
        return;
    }

    int topElement = st.top();
    st.pop();
    insertAtBottom(st, val);
    st.push(topElement);
}

// Recursively reverse the stack
void reverseStack(stack<int> &st) {
    if (st.empty()) return;

    int topElement = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, topElement);
}


void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original stack: ";
    printStack(st);

    reverseStack(st);

    cout << "Reversed stack: ";
    printStack(st);

    return 0;
}
