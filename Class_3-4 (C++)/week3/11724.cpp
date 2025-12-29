#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void ggeuneu(vector<vector<int>>& g, vector<bool>& visited, int n, int start) {

	for (int i = 2; i <= n; i++) {
		if (g[start][i] == 1 && !visited[i]) {
			visited[i] = true;
			ggeuneu(g, visited, n, i);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
	vector<bool> visited(n + 1,false);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g[x][y] = 1;
		g[y][x] = 1;
	}
	int count = 0;
	for (int i = 1; i <= n;i++) {
		if (visited[i] != true) {
			visited[i] = true;
			ggeuneu(g, visited, n, i);
			count ++ ;
		}
	}
	cout << count;
	return 0;
}
