#include <iostream>
#include <vector>
#include<list>
#include<string>
using namespace std;

void resetList(list<int>& L, int N, int M) {


}

void cal(list<int>& L, char AorB, int x, int y) {
	auto it_x = find(L.begin(), L.end(), x);
	int value_x = *it_x;
	L.erase(it_x);
	if (AorB == 'A') {
		auto it_y = find(L.begin(), L.end(), y);
		L.insert(it_y, value_x);
	}
	else if (AorB == 'B') {
		auto it_y = find(L.begin(), L.end(), y+1);
		L.insert(it_y, value_x);
	}
}
/*
int main() {
	int N, M;
	cin >> N >> M;
	list<int> L;
	for (int i = 1; i <= N; i++) L.push_back(i);
	for (int key : L) cout << key;
	char AorB; int x; int y;
	for (int i = 0; i < M; i++) {
		cin >> AorB >> x >> y;
		cal(L, AorB, x, y);
	}
	for (int key : L) cout << key;
	//resetList(L, N, M);

	return 0;
}*/