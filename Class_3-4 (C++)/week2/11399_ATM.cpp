#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, sum = 0, c = 1;
	cin >> N;
	vector<int> p(N);
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}
	sort(p.begin(), p.end());
	for (int i = N-1; i >= 0; i--,c++) {
		sum += p[i] * c;
	}
	cout << sum;
	return 0;
}