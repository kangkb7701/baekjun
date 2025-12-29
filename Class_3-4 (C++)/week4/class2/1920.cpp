#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, m;
	vector<int> arr;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	cin >> m;
	while (m--) {
		int search;
		cin >> search;
		bool find = binary_search(arr.begin(), arr.end(),search);
		cout << find<<'\n';
	}

	return 0;
}