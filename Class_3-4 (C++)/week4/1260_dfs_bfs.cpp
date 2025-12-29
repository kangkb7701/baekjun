#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void dfs(int start,const vector<vector<int>>& g, vector<bool>& visited) {
	visited[start] = true;
	cout << start << " ";
	for (int i = 0; i < g[start].size(); i++) {
		int next = g[start][i];
		if (!visited[next]) {
			dfs(next, g, visited);
		}
	}
}

void bfs(int start, const vector<vector<int>>& g, vector<bool>& visited) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cout << v << " ";

		for (int i = 0; i < g[v].size(); i++) {
			int next = g[v][i];
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, start;
	cin >> n >> m >> start;
	vector<vector<int>> g(n+1, vector<int> ());
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(g[i].begin(), g[i].end());
	}
	//for (int i = 1; i <= n; i++) {
	//	cout << i << " : ";
	//	for (int a : g[i]) { cout << a << " "; }
	//	cout << "\n";
	//}
	vector<bool> visited(n + 1, false);
	dfs(start,g,visited);
	cout << "\n";
	visited.assign(visited.size(), false);
	bfs(start, g, visited);

	return 0;
}