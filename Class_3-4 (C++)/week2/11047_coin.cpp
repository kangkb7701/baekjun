#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k, w;
	int count = 0;
	int a[100];
	cin >> n>> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = n - 1; i >= 0; i--) {
		while (k - a[i] >= 0) {
			k -= a[i];
			count++;
		}
	}
	cout << count;
	return 0;
}