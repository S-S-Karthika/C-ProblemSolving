#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

string PrefixtoPostfix(string prefix) {
    stack<string> answer;
    int n = prefix.length();

    for (int i = n-1; i >=0; i--) {
        // If the character is an operand
        if((prefix[i]>='a' && prefix[i]<='z')||(prefix[i]>='A' && prefix[i]<='Z')||(prefix[i]>='0' && prefix[i]<='9')){
            answer.push(string(1,prefix[i]));
        } 
        // If the character is an operator
        else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/' || prefix[i] == '^') {
           

            // Get the top two elements from the stack
            string operand2 = answer.top();
            answer.pop();
            string operand1 = answer.top();
            answer.pop();

           
            string conversion = operand1 + operand2+ prefix[i] ;
            answer.push(conversion);
        } 
        
    }

    // After processing, there should be exactly one element in the stack
    if (answer.size() != 1) {
        cout << "Error: Invalid prefix expression. Mismatched operators and operands." << endl;
        return "";
    }

    return answer.top(); // The final prefix expression
}

int main() {
    string prefix = "-+a*bc/de";
    //  string prefix = "*+AB-CD";
    //   string prefix = "/-ab*+def";
    cout << "The postfix expression is: " << prefix << endl;

    string postfix =PrefixtoPostfix(prefix);
    if (!postfix.empty()) {
        cout << "The postfix expression is: " << postfix << endl;
    } else {
        cout << "Conversion failed due to errors in the prefix expression." << endl;
    }

    return 0;
}
