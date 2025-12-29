#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int num;
	cin >> num;
	vector<int> s(num);
	vector<int>dp(num);
	for (int i = 0; i < num; i++) {
		int score;
		cin >> score;
		s[i] = score;
	}
	dp[0] = s[0];
	dp[1] = s[0] + s[1];
	dp[2] = max(s[0] + s[2], s[1] + s[2]);
	for (int i = 3; i < num; i++) {
		dp[i] = s[i] + max(dp[i - 2], s[i - 1] + dp[i - 3]);
	}
	//for (int i = 0; i < num; i++) cout << dp[i]<<" ";
	cout << dp[num - 1];



	return 0;
}





int main() {
	int num;
	cin >> num;
	vector<int> s (num);
	vector<vector<int>>dp(num , vector<int>(3));
	for (int i = 0; i < num; i++) {
		int score;
		cin >> score;
		s[i] = score;
	}

	//초기값 설정
	dp[0][0] = s[0];
	dp[0][1] = 0;
	dp[0][2] = dp[0][0] > dp[0][1] ? 0 : 1;
	dp[1][0] = dp[0][0] + s[1];
	dp[1][1] = dp[0][1] + s[1];
	dp[1][2] = dp[1][0] > dp[1][1] ? 0 : 1;

	for (int i = 2; i < num; i++) {
		if (dp[i - 2][2] == 0 && dp[i - 1][2] == 0) { //3칸연속일때
			dp[i][0] = 0;
			dp[i][1] = dp[i - 2][ (dp[i - 2][2]) ] + s[i]; //[][2] 는 0,1중 뭐가 최댓값인지
		}
		else {
			dp[i][0] = dp[i - 1][(dp[i - 1][2])] + s[i];
			dp[i][1] = dp[i - 2][(dp[i - 2][2])] + s[i];
		}
		dp[i][2] = dp[i][0] > dp[i][1] ? 0 : 1;
	}
	cout << min(dp[num - 1][0], dp[num - 1][1]);

	return 0;
}