#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct people {
	int age;
	string name;
	int index;
};

bool compare(people a, people b) {
	if (a.age == b.age) return  a.index < b.index;
	else return a.age < b.age;
}

int main() {
	int N;
	cin >> N;
	vector<people> L(N);
	for (int i = 0; i < N; i++) {
		cin >> L[i].age >>L[i].name ;
		L[i].index = i;
	}
	sort(L.begin(), L.end(),compare);
	
	for (int i = 0; i < N; i++)cout << L[i].age <<" " << L[i].name << "\n";
	return 0;
}