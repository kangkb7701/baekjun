#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m,x;
	int S[10000];
	cin >> m;
	string input;
	while (m--)
	{
		cin >> input;
		if (input != "all" && input != "empty") { //all empty는 x 필요없음
			cin >> x;
		}

		if (input == "add")
		{
			S[x] = 1;
		}
		else if (input == "remove")
		{
			S[x] = 0;
		}
		else if (input == "check")
		{
			if (S[x]) cout << "1\n";
			else cout << "0\n";
		}
		else if (input == "toggle")
		{
			if (S[x]) S[x] = 0;
			else S[x] = 1;
		}
		else if (input == "all")
		{
			for (int i = 1; i <= 20; i++)
				S[i] = 1;
		}
		else
		{
			for (int i = 1; i <= 20; i++)
				S[i] = 0;
		}
	}

	return 0;
}


void set_cal(int m , set<int>& S) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < m; i++) {
		int x;
		string order;
		cin >> order;
		if (order != "all" && order != "empty") { //all empty는 x 필요없음
			cin >> x;
		}
		if (order == "add") S.insert(x);
		else if (order == "remove") S.erase(x);
		else if (order == "check") cout << (S.find(x) != S.end() ? 1 : 0) << endl;
		else if (order == "toggle") {
			if (S.find(x) != S.end()) S.erase(x);
			else S.insert(x);
		}
		else if (order == "all") S = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
		else if (order == "empty") S.clear();
	}
}