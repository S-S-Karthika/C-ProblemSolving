#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int node, vector<vector<int>> &adj, vector<int> &color, int col) {
    for (int neighbor : adj[node]) {
        if (color[neighbor] == col) return false;
    }
    return true;
}

bool solve(int node, int m, vector<vector<int>> &adj, vector<int> &color, int n) {
    if (node == n) return true;

    for (int col = 1; col <= m; col++) {
        if (isSafe(node, adj, color, col)) {
            color[node] = col;
            if (solve(node + 1, m, adj, color, n)) return true;
            color[node] = 0; // backtrack
        }
    }
    return false;
}

bool graphColoring(vector<vector<int>> &adj, int m, int n) {
    vector<int> color(n, 0);
    return solve(0, m, adj, color, n);
}

int main() {
    int n = 4; // number of vertices
    int m = 3; // number of colors

    // Adjacency list representation
    vector<vector<int>> adj = {
        {1, 2, 3}, // node 0 is connected to 1, 2, 3
        {0, 2},    // node 1 is connected to 0, 2
        {0, 1, 3}, // node 2 is connected to 0, 1, 3
        {0, 2}     // node 3 is connected to 0, 2
    };

    if (graphColoring(adj, m, n))
        cout << "Graph can be colored with " << m << " colors.\n";
    else
        cout << "Graph cannot be colored with " << m << " colors.\n";

    return 0;
}
