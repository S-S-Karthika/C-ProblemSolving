#include <iostream>
#include <vector>
using namespace std;


int climbStairsRec(int n) {
    if (n <= 1) return 1;
    return climbStairsRec(n - 1) + climbStairsRec(n - 2);
}


int climbStairsMemo(int n, vector<int>& dp) {
    if (n <= 1) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = climbStairsMemo(n - 1, dp) + climbStairsMemo(n - 2, dp);
}


int climbStairsTab(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    
    return dp[n];
}


int climbStairsOpt(int n) {
    if (n <= 1) return 1;
    int prev = 1, prev2 = 1;
    
    for (int i = 2; i <= n; i++) {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main() {
    int n = 5;
    
    cout << "Recursion: " << climbStairsRec(n) << endl;
    
    vector<int> dp(n + 1, -1);
    cout << "Memoization: " << climbStairsMemo(n, dp) << endl;

    cout << "Tabulation: " << climbStairsTab(n) << endl;
    
    cout << "Space Optimized: " << climbStairsOpt(n) << endl;

    return 0;
}
