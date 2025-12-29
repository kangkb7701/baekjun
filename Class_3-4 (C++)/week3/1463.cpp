#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int calc(int N) {
	int fin = 1;
	int k = 0;
	while (true) {
		if (fin == N) return k;
		else if (fin * 3 <= N) fin = fin * 3;
		else if (fin * 2 <= N) fin = fin * 2;
		else fin = fin + 1;
		k++;
	}
	return k;
}


int main() {
	int N;
	int count = 0;
	cin >> N;
	int k = calc(N);
	cout << k;
	return 0;
}

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1);

    dp[0] = 0;
    dp[1] = 0;
    if (n >= 2) dp[2] = 1;
    if (n >= 3) dp[3] = 1;

    for (int i = 4; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
    }

    cout << dp[n] << endl;

    return 0;
}