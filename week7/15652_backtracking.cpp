#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bt(vector<int> arr, vector<int>& ans, int m);

int main() {
	int n, m, x;
	int i = 1;
	cin >> n >> m;
	vector<int> arr;
	vector<int> ans;
	while (n--) {
		arr.push_back(i);
		i++;
	}
	bt(arr, ans, m);

	return 0;
}

void bt(vector<int> arr, vector<int>& ans, int m) {

	if (ans.size() == m) {
		for (int i : ans) cout << i << " ";
		cout << "\n";
		return;
	}
	else {
		for (int i = 0; i < arr.size(); i++) {
			if (ans.size() == 0 || (ans.size() != 0 && arr[i] >= ans.back())) { //첫숫자이거나 앞에 수가 작다면 추가
				ans.push_back(arr[i]);
				bt(arr, ans, m);
				ans.pop_back();
			}
		}
	}
	return;
}