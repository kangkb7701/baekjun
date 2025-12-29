#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


typedef struct coordinate {
	int x, y;
} coor; // typedef ¿Ã∏ß

bool compare(coor a, coor b) {
	if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}


int main() {

	int n, x, y;
	coor arr[100001];
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arr[i].x = x;
		arr[i].y = y;
	}
	sort(arr,arr+n, compare);

	for (int i = 0; i < n; i++) cout << arr[i].x <<" " << arr[i].y<< "\n";

	return 0;
}

