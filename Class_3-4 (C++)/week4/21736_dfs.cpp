#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = { 0,1,0,-1 };
int person = 0;

void find(vector<vector<char>>& g, int x, int y) {
	g[x][y] = 'V';
	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];
		if (newX >= 0 && newX < g.size() && newY >= 0 && newY < g[0].size() && g[newX][newY] != 'V') {	
			if (g[newX][newY] == 'P') {
				person++;
				find(g, newX, newY);
			}
			else if (g[newX][newY] == 'O') {
				find(g, newX, newY);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m,x,y;
	//int count = 0;
	cin >> n >> m;
	vector<vector<char>> g(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == 'I') {
				x = i;
				y = j;
			}
			g[i][j] = c;
		}
	}
	find(g,x,y);
	if (person == 0) {
		cout << "TT";
	}
	else cout << person;

	return 0;
}