#include <iostream>
#include <stack>
using namespace std;

// Function to check if the parentheses are balanced
bool isBalanced(string str) {
    stack<char> s;

    // Traverse the string
    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            // Push opening brackets onto the stack
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            // If stack is empty, it's unbalanced
            if (s.empty()) return false;

            // Check if the top of the stack matches the closing bracket
            char top = s.top();
            if ((ch == ')' && top == '(') || 
                (ch == '}' && top == '{') || 
                (ch == ']' && top == '[')) {
                s.pop(); // Matching pair, pop from stack
            } else {
                return false; // Mismatch found
            }
        }
    }

    // If stack is empty at the end, it's balanced
    return s.empty();
}

int main() {
    string str;
    // cout << "Enter a string with parentheses: ";
    // cin >> str;

    // str ="{[()]}";
    str ="{[()]";

    if (isBalanced(str)) {
        cout << "The parentheses are balanced!" << endl;
    } else {
        cout << "The parentheses are not balanced!" << endl;
    }

    return 0;
}
