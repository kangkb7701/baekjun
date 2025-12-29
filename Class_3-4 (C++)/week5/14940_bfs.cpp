#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {
	int n, m, x, y, d =0;
	cin >> n>> m;
	vector<vector<int>> g(n, vector<int>(m));
	vector<vector<int>> distance(n, vector<int>(m, 0));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a; 
			//시작좌표 기록
			if (a == 2) {
				x = i;
				y = j;
			}
			//그래프 입력
			g[i][j] = a;
		}
	}

	//bfs로 탐색(순서: 동쪽부터 시계방향)
	//초기값 설정
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

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



	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m;j++) {
			if (g[i][j] != 0 && !visited[i][j]) cout << -1 << " ";
			else	cout << distance[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}