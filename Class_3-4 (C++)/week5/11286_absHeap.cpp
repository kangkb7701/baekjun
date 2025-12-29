//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > absHeap;
//	int n;	
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int x;
//		cin >> x;
//		if (x == 0 && !absHeap.empty()) {
//			cout << absHeap.top().second << "\n";
//			absHeap.pop();
//		}
//		else if (x == 0 && absHeap.empty()) {
//			cout << 0 << "\n";
//		}
//		else absHeap.push({ abs(x),x });
//	}
//	return 0;
//}
