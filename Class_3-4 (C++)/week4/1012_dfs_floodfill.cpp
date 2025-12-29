#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void dfs(int x,int y, vector<vector<int>>& g) {
	g[x][y] = 0;

	for (int i = 0; i < 4;i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];
		if (newX >= 0 && newX < g.size() && newY >= 0 && newY < g[0].size() && g[newX][newY] == 1) { 
			dfs(newX, newY, g); 
		}
	}
}


int main() {
	int T,m, n, k;
	cin >> T;
	while (T--) { 
		cin >> m >> n >> k; //가로(col),세로(row),배추개수
		vector<vector<int>>g (n, vector<int>(m,0));

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> y >> x;
			g[x][y] = 1;
		}
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (g[i][j] == 1) { 
					count++;
					dfs(i, j, g); 
				}
			}
			
		}
		cout << count << "\n";
	}

	return 0;
}