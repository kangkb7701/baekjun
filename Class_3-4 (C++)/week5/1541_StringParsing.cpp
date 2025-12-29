#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string line;
	cin >> line;
	
	int result = 0;
	bool flag = false;
	string number = "";

	for (char c : line) {

		if (c == '-' || c == '+') {
			if (flag) {
				result -= stoi(number);
			}
			else {
				result += stoi(number);
			}
			number = "";
			if (c == '-') {
				flag = true;
			}
		}
		else {
			number += c;
		}
		
	}
	result = flag ? (result - stoi(number)) : (result + stoi(number));
	cout << result;	

	return 0;
}