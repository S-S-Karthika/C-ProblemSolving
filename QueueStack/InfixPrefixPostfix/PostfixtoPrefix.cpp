#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

string PostfixtoPrefix(string postfix) {
    stack<string> answer;
    int n = postfix.length();

    for (int i = 0; i < n; i++) {
        // If the character is an operand
        if (isalnum(postfix[i])) {
            answer.push(string(1, postfix[i]));
        } 
        // If the character is an operator
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
            // Check if there are at least two operands in the stack
            if (answer.size() < 2) {
                cerr << "Error: Invalid postfix expression. Not enough operands for operator '" << postfix[i] << "'." << endl;
                return "";
            }

            // Get the top two elements from the stack
            string operand2 = answer.top();
            answer.pop();
            string operand1 = answer.top();
            answer.pop();

            // Form the prefix expression
            string conversion = postfix[i] + operand1 + operand2;
            answer.push(conversion);
        } 
        // Handle unexpected characters
        else {
            cerr << "Error: Invalid character '" << postfix[i] << "' in postfix expression." << endl;
            return "";
        }
    }

    // After processing, there should be exactly one element in the stack
    if (answer.size() != 1) {
        cerr << "Error: Invalid postfix expression. Mismatched operators and operands." << endl;
        return "";
    }

    return answer.top(); // The final prefix expression
}

int main() {
    // string postfix = "ab-ac/d-+";
    //  string postfix = "ab+cd-*";
      string postfix = "abc*+de/-";
    cout << "The postfix expression is: " << postfix << endl;

    string prefix = PostfixtoPrefix(postfix);
    if (!prefix.empty()) {
        cout << "The prefix expression is: " << prefix << endl;
    } else {
        cerr << "Conversion failed due to errors in the postfix expression." << endl;
    }

    return 0;
}
