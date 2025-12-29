#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> origin;
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		origin.push_back(x);
	}
	vector<int> arr = origin;
	sort(arr.begin(), arr.end());
	auto it = unique(arr.begin(), arr.end());
	arr.erase(it, arr.end());

	//시간초과, 브루트포스 방식
	/*for (int i = 0; i < origin.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {
			if (origin[i] == arr[j]) {
				cout << j << " ";
			}
		}
	}*/
	for (int val : origin) {
		// 이진 탐색을 사용하여 arr에서 val의 위치 찾기
		auto it = lower_bound(arr.begin(), arr.end(), val);
		if (it != arr.end() && *it == val) {
			cout << distance(arr.begin(), it) << " ";
		}
	}

	return 0;
}