#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> dp(n+1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		dp[i] = dp[i - 1] + num;
	}
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		cout << dp[e] - dp[s - 1] << '\n';
	}

	return 0;
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> num (n+1);
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		num[i] = a;
	}
	for (int i = 0; i < m; i++) {
		int o, p;
		int sum = 0;
		cin >> o >> p;
		for (int j = o; j <= p; j++) {
			sum += num[j];
		}
		cout << sum << "\n";
	}

	return 0;
}