#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {
	int n, m;
	cin >> m >> n; //가로 세로
	vector<vector<int>> g(n, vector<int>(m));
	queue<pair<int,int>> q;
	queue<pair<int, int>> emp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
			if (g[i][j] == 1) q.push({ i,j });
			if (g[i][j] == -1) emp.push({ i,j });
		}
	}
	if (q.size() + emp.size() == m * n) {
		cout << 0;
		return 0;
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < g.size() && ny >= 0 && ny < g[0].size() && g[nx][ny] == 0) { //범위내의 익지 않은 토마토라면
				g[nx][ny] = g[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int a : g[i]) {
			if (a == 0) {
				cout << -1;
				return 0;
			}
			else result = a > result ? a : result;
		}
	}
	cout << result - 1; //max =7 이면 1+6 즉, 6일이 걸렸다는 뜻

	return 0;
}