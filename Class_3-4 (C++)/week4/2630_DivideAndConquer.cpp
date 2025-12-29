#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int blue = 0, white = 0;

void cutting(int x, int y, int n, vector<vector<int>>& g) {
    bool cut = false; // 잘라야하는지 
    int first_color = g[x][y]; // 첫번째칸의 색
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (g[i][j] != first_color) { // 중간에 다른색이 나오면
                cut = true; // 잘라야함.
                break;
            }
        }
    }

    if (cut) { // 잘라야하는 색종이면 
        cutting(x, y, n / 2, g); // 위쪽에 왼쪽 파트
        cutting(x, y + n / 2, n / 2, g); //위쪽에 오른쪽 파트
        cutting(x + n / 2, y, n / 2, g); // 아래쪽에 왼쪽 파트
        cutting(x + n / 2, y + n / 2, n / 2, g); // 아래쪽에 오른쪽 파트
    }

    else {
        if (first_color == 1) // 파란색
            blue++;
        else // 흰색
            white++;
    }
}


int  main() {

	int n;
	cin >> n;
	vector<vector<int>> g(n,vector<int> (n));
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			g[i][j] = a;
		}
	}

    cutting(0,0,8,g);
    cout <<white<<"\n" << blue;
	return 0;
}