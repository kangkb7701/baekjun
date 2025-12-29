#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>

using namespace std;

int gcd(int a, int b) // 조건 : a > b
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y; //마지막해 <m:n> 찾는 해 <x:y>

		int lastyear = m >= n ? (m * n / gcd(m, n)) : (m * n / gcd(m, n));  //최소공배수

		int year = x;
		bool flag = false;
		while (year <= lastyear) {
			int newY = year % n;
			if (newY == 0) newY = n;
			//정답이라면
			if (newY == y) {
				cout << year << "\n";
				flag = true;
				break;
			}
			year += m;
		}
		if (!flag) cout << -1<<"\n";

	}
	return 0;
}




//brute force
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int T;
//	cin >> T;
//	vector<int> ans;
//	while (T--) {
//		int m, n, x, y;
//		cin >> m >> n >> x >> y;
//		int a = 1, b = 1;
//		int year = 1;
//		bool flag = false;
//		bool finish = false;
//		while (!finish) {
//			if (a == m && b == n) finish = true;
//			if (a < m) a++;
//			else a = 1;
//			if (b < n) b++;
//			else b = 1;
//			year++;
//			if (a == x && b == y) {
//				flag = true;
//				break;
//			}
//		}
//		if (!flag) ans.push_back(-1);
//		else ans.push_back(year);
//	}
//	for (int i : ans) cout << i<<" ";
//	return 0;
//}