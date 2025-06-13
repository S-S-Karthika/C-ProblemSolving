#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<unordered_set>
using namespace std;

// Check if string is valid parentheses string
bool isValid(string s) {
    int count = 0;
    for (char ch : s) {
        if (ch == '(') count++;
        else if (ch == ')') {
            count--;
            if (count < 0) return false;
        }
    }
    return count == 0;
}

void combination(int pos, string input, unordered_set<string>& res, string curr, int toRemove) {
    if (toRemove < 0) return;

    if (pos == input.size()) {
        if (toRemove == 0 && isValid(curr)) {
            res.insert(curr);  // use set to avoid duplicates
        }
        return;
    }

    // Option 1: Remove current char
    if (input[pos] == '(' || input[pos] == ')') {
        combination(pos + 1, input, res, curr, toRemove - 1);
    }

    // Option 2: Keep current char
    curr.push_back(input[pos]);
    combination(pos + 1, input, res, curr, toRemove);
    curr.pop_back(); // backtrack
}

int main() {
    string s = "()())()";

    // Calculate minimum invalid parentheses
    int left = 0, right = 0;
    for (char ch : s) {
        if (ch == '(') {
            left++;
        } else if (ch == ')') {
            if (left > 0) left--;
            else right++;
        }
    }

    unordered_set<string> result;
    combination(0, s, result, "", left + right);

    for (const string& ans : result) {
        cout << ans << endl;
    }

    return 0;
}
