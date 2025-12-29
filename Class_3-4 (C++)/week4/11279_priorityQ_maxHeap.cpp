#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int> maxHeap;
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x != 0) maxHeap.push(x);
		else if (x == 0 && maxHeap.empty()) cout << 0 << "\n";
		else {
			cout<<maxHeap.top()<<"\n";
			maxHeap.pop();
		}
	}
	return 0;
}