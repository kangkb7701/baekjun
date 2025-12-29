#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long N, M;
	cin >> N >> M;
	vector<int> H;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		H.push_back(t);
	}
	sort(H.begin(), H.end());
	long long low = 0;
	long long high = H[N - 1]; //최대길이
	long long max = 0; //잘라서 들고갈 나무 합계

	while (low <= high) {
		long long sum = 0;
		long long cut = (low + high) / 2;
		for (int i = 0; i < N; i++) {
			if (H[i] - cut > 0) sum += H[i] - cut;
		}
		if (sum >= M) {
			max = cut;
			low = cut + 1;
		}
		else {
			high = cut - 1;
		}
	}
	cout << max;
	return 0;
}