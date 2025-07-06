#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bt(vector<int> arr, vector<int>& ans,vector<bool>&visited, int m);

int main() {
	int n,m,x;
	cin >> n>>m;
	vector<int> arr;
	vector<int> ans;
	vector<bool> visited(n, false);
	while (n--) {
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(),arr.end());
	bt(arr, ans,visited, m);
	
	return 0;
}

void bt(vector<int> arr, vector<int>& ans, vector<bool> &visited, int m) {
	
	if (ans.size() == m) {
		for (int i : ans) cout << i << " ";
		cout << "\n";
		return;
	}
	else {
		for (int i = 0; i < arr.size(); i++) {
			if (!visited[i]) { //방문안했다면
				ans.push_back(arr[i]);
				visited[i] = true;
				bt(arr, ans, visited, m);
				ans.pop_back();
				visited[i] = false;
			}
		}
	}
	return;
}