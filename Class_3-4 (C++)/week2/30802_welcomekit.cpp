#include <iostream>

using namespace std;

int main() {
	int n, t, p, count = 0;
	cin >> n;
	int a[6];
	for (int i = 0; i < 6; i++) cin >> a[i];
	cin >> t >> p;
	for (int i = 0; i < 6; i++) {
		if(a[i]%t == 0) count += a[i] / t;
		else count += a[i] / t + 1;
		
	}
	cout << count<<"\n";
	cout << n / p << " " << n % p;


	return 0;
}