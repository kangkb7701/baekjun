#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[1001] = { 1,1, };
	for (int i = 1; i < n; i++) {
		arr[i+1] += ((arr[i - 1] + arr[i])%10007);
	}
	cout << arr[n];

	return 0;
}