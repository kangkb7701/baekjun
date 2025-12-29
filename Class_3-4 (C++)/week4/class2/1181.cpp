#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

bool compareWords(const string& a, const string& b) {
	if (a.size() != b.size()) {
		return a.size() < b.size(); // 길이가 다르면 짧은 순으로 정렬
	}
	return a < b; // 길이가 같으면 사전순으로 정렬
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	set<string> s;
	int n;
	cin >> n;
	while (n--) {
		string word;
		cin >> word;;
		s.insert(word);
	}
	vector<string> s1 (s.begin(), s.end());
	sort(s1.begin(), s1.end(), compareWords);

	for (auto t : s1) {
		cout << t<<"\n";
	}

	return 0;
}