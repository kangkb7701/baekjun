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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> g (n, vector<int>(m));
	vector<vector<int>> distance(n, vector<int>(m, 0));
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	for(int i =0;i<n;i++) {
		string line;
		cin >> line;
		for (int j = 0; j < line.size();j++) {
			g[i][j] = (int)line[j] - '0';
		}
	}
	//bfs로 탐색(순서: 동쪽부터 시계방향)
	//초기값 설정
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = true;
	distance[0][0] = 1;

	while (!q.empty()) {
		// 큐 맨앞 빼고 그 좌표에서 탐색
		int X = q.front().first;
		int Y = q.front().second;

		q.pop();
		for (int k = 0; k < 4; k++) {
			//새 좌표 설정
			int newX = X + dx[k];
			int newY = Y + dy[k];
			if (newX >= 0 && newX < n && newY >= 0 && newY < m && g[newX][newY] != 0 && !visited[newX][newY]) {
				//방문하지 않고 벽이 아닌 범위 내의 새 좌표는 탐색대상 -> 큐에 push
				q.push({ newX,newY });
				//방문했다 표시
				visited[newX][newY] = true;
				distance[newX][newY] = distance[X][Y] + 1; //이전 큐의 distance에서 +1
			}
		}
	}
	cout << distance[n - 1][m - 1];

	return 0;
}