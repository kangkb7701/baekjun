#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, b, m;
	cin >> n >> m >> b;
	vector<vector<int>> g(n, vector<int> (m));
	set<int> h; // 블록높이, 높이의 개수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			g[i][j] = x;
			h.insert(x);
		}
	}

	int sec_min = INT_MAX, h_max = 0;
	for (int s = 0; s<=256;s++) { // s가 기준
			int build = 0, destroy = 0;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (g[i][j] > s) destroy += g[i][j] - s;//높으면 잘라내야지 -> 인벤에 저장
					else if (g[i][j] < s) {
						build += s - g[i][j]; //낮으면 더 지어 -> 인벤에서 가져와
					}
				}
			}
			// 잘라낸거 + 인벤에 있던거 >= build (지어야할 양) 일때만 ㄱㄴ
			if (destroy + b >= build) {
				int sec = destroy*2 + build; // 현재 구한 시간
				sec_min = min(sec_min, sec);
				//cout << build << " " << destroy<<"\n";
				h_max = sec <= sec_min ? s : h_max; //현재구한 시간이 더 작을때만 h값 갱신가능
			}
	}
	cout << sec_min << " " << h_max;

	return 0;
}