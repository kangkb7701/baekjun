#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a, b;
	cin >> n >> m; // node, edge
	
	vector<vector<int>> cnt(n+1); // connection 정보
	vector<vector<int>> dist(n + 1, vector<int>(n + 1,0));
	vector<pair<int, int>> bcnN; //baconNum 합계

	while (m--) {
		cin >> a >> b;
		cnt[a].push_back(b);
		cnt[b].push_back(a);
	}

	//for (int i = 0; i <= n;i++) {
	//	for (int j : cnt[i]) {
	//		cout << j << " ";
	//	}
	//	cout << "\n";
	//}

	//bfs로 탐색
	for (int start = 1; start <= n; start++) { //시작노드
		vector<bool> visited (n+1,false);
		queue<int> q;
		visited[start] = true;
		q.push(start);
		while (!q.empty()) {
			int v = q.front();
			q.pop();

			for (int i = 0; i < cnt[v].size(); i++) {
				int next = cnt[v][i];
				if (!visited[next]) {
					visited[next] = true;
					q.push(next);
					dist[start][next] = dist[start][v] + 1;
					dist[next][start] = dist[v][start] + 1;
					//cout << start<<" " << next<<" " << dist[start][next]<<"\n";
				}
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (auto j : dist[i]) {
			sum += j;
		}
		bcnN.push_back({sum,i});
		sum = 0;
	}
	sort(bcnN.begin(), bcnN.end());
	cout << bcnN[0].second;
	return 0;
}