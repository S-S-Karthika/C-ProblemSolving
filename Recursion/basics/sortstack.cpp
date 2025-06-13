#include <iostream>
#include <stack>
using namespace std;

void method1(stack<int>& input) {
    stack<int> temp;

    while (!input.empty()) {
        int val = input.top();
        input.pop();

        while (!temp.empty() && temp.top() > val) {
            input.push(temp.top());
            temp.pop();
        }

        temp.push(val);
    }

    // Optional: Move sorted elements back to input stack
    while (!temp.empty()) {
        input.push(temp.top());
        temp.pop();
    }
}

// Insert element into the sorted stack
void insertSorted(stack<int> &st, int val) {
    if (st.empty() || st.top() <= val) {
        st.push(val);
        return;
    }

    int top = st.top();
    st.pop();
    insertSorted(st, val);
    st.push(top);
}

// Recursively sort the stack
void sortStack(stack<int> &st) {
    if (st.empty()) return;

    int top = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, top);
}

// Print stack top to bottom
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(2);
    st.push(3);
    st.push(1);
    st.push(4);

    cout << "Original Stack: ";
    printStack(st);

    sortStack(st);

    cout << "Sorted Stack: ";
    printStack(st);

    return 0;
}
