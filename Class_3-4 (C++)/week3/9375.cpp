#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int test_num, n;
	cin >> test_num;
	for (int k = 0; k < test_num; k++) {
		map<string, int> c;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string name, where;
			cin >> name>>where;
			if (c.find(where) == c.end())
			{
				c.insert({ where, 1 });
			}
			else
				c[where]++;
		}
		int ans = 1;
		for (auto i : c)
		{
			ans *= (i.second + 1);
		}
		ans -= 1;
		cout << ans << '\n';
	}
	return 0;
}

