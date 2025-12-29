#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
//
//int main() {
//
//	int N, K;
//	queue<int> que;
//
//	cin >> N >> K;
//	for (int i = 1; i <= N; i++) que.push(i);
//
//	while (que.size() > 1) {
//		int first = que.front();	
//		int rep = min(K, (int)que.size());
//		for (int i = 0; i < rep; i++) que.pop();
//		que.push(first);
//		//cout << que.size() <<" " << que.front()<<endl;
//	}
//	cout << que.front();
//}