#include <bits/stdc++.h>
using namespace std;
//switch with string is invalid in C++, so using if-else
// Function to convert 4-bit binary string to hexadecimal character


char binarytohex(string ch) {
    if(ch == "0000") return '0';
    else if(ch == "0001") return '1';
    else if(ch == "0010") return '2';
    else if(ch == "0011") return '3';
    else if(ch == "0100") return '4';
    else if(ch == "0101") return '5';
    else if(ch == "0110") return '6';
    else if(ch == "0111") return '7';
    else if(ch == "1000") return '8';
    else if(ch == "1001") return '9';
    else if(ch == "1010") return 'A';
    else if(ch == "1011") return 'B';
    else if(ch == "1100") return 'C';
    else if(ch == "1101") return 'D';
    else if(ch == "1110") return 'E';
    else if(ch == "1111") return 'F';
    else return 'o';
}

int main() {
    string binary = "001100001001101010111100";
    
    // Padding if length is not multiple of 4
    while(binary.length() % 4 != 0) {
        binary = "0" + binary;
    }

    string ans = "";
    for(int i = 0; i < binary.length(); i += 4) {
        string curr = binary.substr(i, 4);
        char val = binarytohex(curr);
        if(val == 'o') {
            cout << "INVALID INPUT";
            return 0;
        }
        ans += val;
    }
    cout << ans;
    return 0;
}
