#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <math.h>

using namespace std;

int result = 0;
int a, b;
int dx[4] = { 0,0,1,1 };
int dy[4] = { 0,1,0,1 };

void divideZ(int sX, int eX, int sY, int eY) {
	int range = eX - sX + 1;

	if(range <= 2) {
		int nowX, nowY;
		for (int i = 0; i < 4; i++) {
			nowX = sX + dx[i];
			nowY = sY + dy[i];
			result++;
			if (nowX == a && nowY == b) {
				cout << result - 1;
				return;
			}
		}
	}

	int midX = (sX + eX) / 2;
	int midY = (sY + eY) / 2;

	if (a <= midX && b <= midY) divideZ(sX, midX, sY, midY); // 왼쪽 위
	else if (a <= midX && b > midY) {
		result += pow(range / 2, 2);
		divideZ(sX, midX, midY + 1, eY); // 오른쪽 위
	}
	else if (a > midX && b <= midY) {
		result += 2 * pow(range / 2, 2);
		divideZ(midX + 1, eX, sY, midY); // 왼쪽 아래
	}
	else {
		result += 3 * pow(range / 2, 2);
		divideZ(midX + 1, eX, midY + 1, eY); // 오른쪽 아래
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n>>a>>b;
	int size = pow(2, n);

	divideZ(0, size - 1, 0, size - 1); // 0~3까지
	return 0;
}