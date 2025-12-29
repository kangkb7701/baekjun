#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t,num;
	cin >> t;
	vector<int> arr(t);
	int cache[12] = { 0,1,2,4, };

	for (int i = 4; i < 11; i++) {
		cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
	}
	for (int i = 0; i < t; i++) { 
		cin >> num;
		cout << cache[num] << "\n";
	}

	return 0;
}