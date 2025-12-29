#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	cin >> n;
	vector<int> fruits; //탕후루 꽂은 순서
	map<int, int> classify; // 종류별 개수 분류
	while (n--) {
		cin >> x;
		fruits.push_back(x);
	}
	int left = 0, max_len = 0;

	for (int right = 0; right < fruits.size(); right++) { //right와 left 사이에 과일이 2종류만 있는 max_len 계산
		classify[fruits[right]]++;

		while (classify.size() > 2) {
			classify[fruits[left]]--;

			if (classify[fruits[left]] == 0) classify.erase(fruits[left]);
			left++; // 왼쪽 포인터 오른쪽 이동
		}
		max_len = max(max_len, right - left + 1);
	}
	cout << max_len;
	return 0;
}

//	deque<int> deq;
//	map<int, int> mp;
//	while (n--) {
//		cin >> x;
//		deq.push_back(x);
//		mp[x]++; //x는 과일번호, value는 갯수
//	}
//	//for (auto d = mp.begin(); d != mp.end();d++) cout << d->first << " " << d->second << " ";
//	
//	while (mp.size() > 2) {
//		//deq.front는 과일번호
//		if (mp[deq.front()] <= mp[deq.back()]) {
//			mp[deq.front()]--;
//			deq.pop_front();
//		}
//		else {
//			mp[deq.back()]--;
//			deq.pop_back();
//		}
//		for (auto it = mp.begin(); it != mp.end(); ) {
//			if (it->second == 0) it = mp.erase(it);
//			else ++it;
//		}
//	}
//	int sum = 0;
//	for (auto d = mp.begin(); d != mp.end(); d++) sum += d->second;
//	cout << sum;
//
//	return 0;
//}