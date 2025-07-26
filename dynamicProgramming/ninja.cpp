#include <bits/stdc++.h>
using namespace std;

// ---------- Approach 1: Recursion ----------
int recursion(int day, int prev, vector<vector<int>> &points) {
    if (day == 0) {
        int maxi = 0;
        for (int i = 0; i < 3; i++) {
            if (i != prev) maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }

    int maxi = 0;
    for (int i = 0; i < 3; i++) {
        if (i != prev) {
            int point = points[day][i] + recursion(day - 1, i, points);
            maxi = max(maxi, point);
        }
    }

    return maxi;
}

// ---------- Approach 2: Memoization ----------
int memo(int day, int prev, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if (day == 0) {
        int maxi = 0;
        for (int i = 0; i < 3; i++) {
            if (i != prev) maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }

    if (dp[day][prev] != -1) return dp[day][prev];

    int maxi = 0;
    for (int i = 0; i < 3; i++) {
        if (i != prev) {
            int point = points[day][i] + memo(day - 1, i, points, dp);
            maxi = max(maxi, point);
        }
    }

    return dp[day][prev] = maxi;
}

// ---------- Approach 3: Tabulation ----------
int tabulation(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }

    return dp[n - 1][3];
}

// ---------- Approach 4: Space Optimization ----------
int spaceOptimized(int n, vector<vector<int>> &points) {
    vector<int> prev(4, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max({points[0][0], points[0][1], points[0][2]});

    for (int day = 1; day < n; day++) {
        vector<int> curr(4, 0);
        for (int last = 0; last < 4; last++) {
            int maxi = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int point = points[day][task] + prev[task];
                    maxi = max(maxi, point);
                }
            }
            curr[last] = maxi;
        }
        prev = curr;
    }

    return prev[3];
}

// ---------- Main Function ----------
int main() {
    int n = 3;
    vector<vector<int>> points = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    cout << "1. Recursion: " << recursion(n - 1, 3, points) << endl;

    vector<vector<int>> dp(n, vector<int>(4, -1));
    cout << "2. Memoization: " << memo(n - 1, 3, points, dp) << endl;

    cout << "3. Tabulation: " << tabulation(n, points) << endl;

    cout << "4. Space Optimization: " << spaceOptimized(n, points) << endl;

    return 0;
}
