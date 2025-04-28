#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int node, int color[], vector<vector<int>> &graph, int n, int col) {
    for (int k = 0; k < n; k++) {
        if (k != node && graph[k][node] == 1 && color[k] == col) {
            return false;
        }
    }
    return true;
}

bool solve(int node, vector<vector<int>> &graph, int m, int n, int color[]) {
    if (node == n) return true;

    for (int col = 1; col <= m; col++) {
        if (isSafe(node, color, graph, n, col)) {
            color[node] = col;
            if (solve(node + 1, graph, m, n, color)) return true;
            color[node] = 0; // backtrack
        }
    }
    return false;
}

bool graphColoring(vector<vector<int>> &graph, int m, int n) {
    int color[n] = {0};
    return solve(0, graph, m, n, color);
}

int main() {
    int n = 4; // number of vertices
    int m = 3; // number of colors

    // Graph represented as adjacency matrix
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    if (graphColoring(graph, m, n))
        cout << "Graph can be colored with " << m << " colors.\n";
    else
        cout << "Graph cannot be colored with " << m << " colors.\n";

    return 0;
}
