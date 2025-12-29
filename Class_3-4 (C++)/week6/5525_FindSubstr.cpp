#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>

using namespace std;

//int countSubstring(const string& s, const string& target) {
//	int count = 0;
//	size_t pos = 0;
//
//	while ((pos = s.find(target, pos)) != s.npos) {
//		count++;
//		pos += 1; // 한 글자만 이동 (겹침 허용)
//	}
//
//	return count;
//}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	string s;
	cin >> n >> m >> s;

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		if (s[i] == 'I') {
			int k = 0;
			while (i + 2 < m && s[i + 1] == 'O' && s[i + 2] == 'I' ) {
				k++;
				i += 2;
			}
			if (k >= n) cnt += k - n + 1;
		}
	}
	cout << cnt;

	///*for (char i : find) cout << i;
	//cout << s;*/

	//int result = countSubstring(s, find);
	//cout << result;


	return 0;
}