#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int makeM(vector<int> S,int N,int M) {
	int num = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N ; j++) {
			if (S[i] + S[j] == M) num++;
		}
	}
	return num;
}

int makeM(vector<int> S, int N, int M) {
	sort(&S[0], &S[N]);
	int ans = 0;
	int s = 0, e = N - 1;
	while (s < e) {
		if (S[s] + S[e] == M) {
			ans++;
			s++; e--;
		}
		else if (S[s] + S[e] < M)
			s++;
		else e--;
	}

	return ans;
}

int main() {

	int N, M,val;
	cin >> N >> M;
	vector<int> S(N);
	for (int i = 0; i < N; i++) {
		cin >> val;
		S[i] = val;
	}
	cout << makeM(S, N, M);
	
	return 0;
}

/*
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, a[15005], ans;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	sort(&a[0], &a[n]);
	int s = 0, e = n - 1;
	while (s < e) {
		if (a[s] + a[e] == m) {
			ans++;
			s++; e--;
		}
		else if (a[s] + a[e] < m)
			s++;
		else e--;
	}
	printf("%d", ans);
	return 0;
}
*/
