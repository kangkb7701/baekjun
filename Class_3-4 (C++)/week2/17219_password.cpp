#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<string, string> L;

int main() {

	int n, m;
	string s,t;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s >> t;
		L[s] = t;
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		cout << L[s]<<"\n";
	}


	return 0;
}