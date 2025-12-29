#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> minHeap;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0 && !minHeap.empty()) {
			cout << minHeap.top() << "\n";
			minHeap.pop();
		}
		else if (x == 0 && minHeap.empty()) {
			cout << 0 << "\n";
		}
		else minHeap.push(x);
	}
	return 0;
}