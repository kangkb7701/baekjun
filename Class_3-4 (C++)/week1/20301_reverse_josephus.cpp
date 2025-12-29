#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

void reverse_deq(deque<int>& deq) {
	deque<int> temp;
	int size = deq.size();
	for (int i = 0; i < size; i++) {
		temp.push_front(deq.front());
		deq.pop_front();
	}
	deq = temp;
	//for (int i = 0; i < deq.size(); ++i) cout << deq[i] << " ";
}

void reverse_josephus(deque<int>& deq,int N,int K,int M) {

	int count = 0;
	while (deq.size() > 1) {
		if (count % M == 0 && count > 0) {
			reverse_deq(deq);// count를 M으로 나눈 나머지 == 0 : M명째마다 반전
			//cout << "완료\n";
		}
		for (int i = 0; i < K - 1; i++) {
			deq.push_back(deq.front());
			deq.pop_front();
		}
		cout << deq.front()<<"\n";
		deq.pop_front();
		
		count++;
	}
	cout << deq.front();
}
/*
int main() {
	int N, K, M; //총N명 K번째사망 M명째마다 반전
	cin >> N >> K >> M;
	deque<int> deq;
	for (int i = 1; i <= N; i++) deq.push_back(i);
	reverse_josephus(deq, N, K, M);

	return 0;
}*/