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
int home = 0;

void dfs(vector<vector<int>>& g, vector<vector<bool>>& visited, int i, int j) {
	visited[i][j] = true;
	for (int k = 0; k < 4; k++) {
		int newX = i + dx[k];
		int newY = j + dy[k];
		//집이 있고 방문안했다면
		if (newX >=0 && newX < g.size()&& newY >=0 && newY < g[0].size() && g[newX][newY] != 0 && !visited[newX][newY]) {
			home++;
			dfs(g, visited, newX, newY);  
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> g(n, vector<int>(n));
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	vector<int> house;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			g[i][j] = s[j] - '0';
		}
	}

	//dfs로 탐색
	int cnt = 0; //단지 수, 집수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (g[i][j] != 0 && !visited[i][j]) {
				visited[i][j] = true;
				home = 1;
				dfs(g, visited, i, j);    //집이 있고 방문안했다면
				cnt++;
				house.push_back(home);
			}
		}
	}
	sort(house.begin(), house.end());
	cout << cnt << "\n";
	for (int a : house) cout << a << "\n";

	return 0;
}