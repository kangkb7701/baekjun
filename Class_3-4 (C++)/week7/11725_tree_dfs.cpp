#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>>& g, vector<bool>& visited, vector<int>& node, int i) {
    visited[i] = true;
    for (int next : g[i]) {
        if (!visited[next]) {
            node[next] = i;
            dfs(g, visited, node, next);
        }
    }
}

int main() {
    int n, x, y;
    cin >> n;
    vector<int> node(n + 1, 0);
    vector<vector<int>> g(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(g, visited, node, 1);

    for (int i = 2; i <= n; i++) {
        cout << node[i] << "\n";
    }

    return 0;
}
