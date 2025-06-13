#include <iostream>
#include <string>
using namespace std;

void helper(string num, int target, int pos, long currVal, long prevNum, int& count) {
    if (pos == num.length()) {
        if (currVal == target) count++;
        return;
    }

    for (int i = pos; i < num.length(); i++) {
        // Avoid numbers with leading zeros
        if (i != pos && num[pos] == '0') break;

        string part = num.substr(pos, i - pos + 1);
        long currNum = stol(part);

        if (pos == 0) {
            // First number, start without any operator
            helper(num, target, i + 1, currNum, currNum, count);
        } else {
            // '+'
            helper(num, target, i + 1, currVal + currNum, currNum, count);
            // '-'
            helper(num, target, i + 1, currVal - currNum, -currNum, count);
            // '*'
            helper(num, target, i + 1, currVal - prevNum + prevNum * currNum, prevNum * currNum, count);
        }
    }
}

int countExpressions(string num, int target) {
    int count = 0;
    helper(num, target, 0, 0, 0, count);
    return count;
}

int main() {
    string num = "123";
    int target = 6;
    cout << "Number of valid expressions: " << countExpressions(num, target) << endl;
    return 0;
}
