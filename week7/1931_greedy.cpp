#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> sched;
	while (n--) {
		int a,b;
		cin >> a >> b;
		sched.push_back({ b,a });
	}

	sort(sched.begin(), sched.end());
	for (auto s : sched) cout << s.first << " " << s.second << "\n";
	int time = sched[0].first;
	int task = 1;
	for (int i = 1; i < sched.size(); i++) {
		if (sched[i].second >= time) {
			time = sched[i].first;
			task++;
		}
	}
	cout << task;
	return 0;
}