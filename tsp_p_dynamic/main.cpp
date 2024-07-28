#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int tsp(int graph[10][10], int n) {
    int max_subsets = pow(2, n);
    int dp[16][4];
    for (int i = 0; i < max_subsets; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }
    dp[1][0] = 0;

    for (int mask = 1; mask < max_subsets; mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            for (int v = 0; v < n; v++) {
                if (u != v && (mask & (1 << v))) {
                    dp[mask][u] = min(dp[mask][u], dp[mask ^ (1 << u)][v] + graph[v][u]);
                }
            }
        }
    }

    int ans = INF;
    for (int v = 1; v < n; v++) {
        ans = min(ans, dp[max_subsets - 1][v] + graph[v][0]);
    }

    return ans;
}

int main() {
    int n = 4;
    /*cout << "Enter the number of cities: ";
    cin >> n;

    int graph[10][10];
    cout << "Enter the adjacency matrix for the graph:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }*/
    int graph[10][10] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout << "Minimum cost to visit all cities: " << tsp(graph, n) << endl;
}
