#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>

using namespace std;

void bfs(const vector<vector<int>>& g, vector<vector<bool>> visited, vector<vector<int>>& connection, int i) {
	set<int> s;
	queue<int> q;
	q.push(i);
	while (!q.empty()) {
		int find = q.front();
		q.pop();
		for (int k = 0; k < g.size(); k++) {
			if (g[find][k] == 1 && !visited[find][k]) {
				q.push(k);
				visited[find][k] = true;
				s.insert(k);
			}
		}
	}
	for (auto a : s) {
		connection[i][a] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	vector<vector<int>> g(n, vector<int>(n));
	vector<vector<bool>> visited(n, vector<bool>(n));
	vector<vector<int>> connection(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			g[i][j] = x;
			visited[i][j] = false;
			connection[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		bfs(g, visited, connection,i); //시작노드 i 바꿔가며 모두 탐색
	}

	for (int i = 0; i < n; i++) {
		for (int a : connection[i]) cout << a << " ";
		cout << "\n";
	}


	return 0;
}