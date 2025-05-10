#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
using namespace std;


//here k is length of the combination and n is sum
// we have to use numbers from 1 to 9 and we can use each number only once
// we have to find all the combinations of k numbers that sum to n


class Solution {
public:
    void backtrack(int start, int k, int n, vector<int>& combo, vector<vector<int>>& result) {
        if (combo.size() == k) {
            if (n == 0) {
                result.push_back(combo);
            }
            return;
        }

        for (int i = start; i <= 9; ++i) {
            if (i > n) break;  // No point in continuing
            combo.push_back(i);
            backtrack(i + 1, k, n - i, combo, result);
            combo.pop_back();  // backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combo;
        backtrack(1, k, n, combo, result);
        return result;
    }
};

int main() {
    Solution sol;

    int k = 3, n = 5;
    vector<vector<int>> combinations = sol.combinationSum3(k, n);

    cout << "Combinations of " << k << " numbers that sum to " << n << ":\n";
    for (const auto& combo : combinations) {
        cout << "[";
        for (size_t i = 0; i < combo.size(); ++i) {
            cout << combo[i];
            if (i != combo.size() - 1) cout << ",";
        }
        cout << "]\n";
    }

    return 0;
}
