#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void pita(int A[]){
	while (true) {
		cin >> A[0] >> A[1] >> A[2];
		if (A[0] == 0 && A[1] == 0 && A[2] == 0) break;
		sort(A, A+3);
		if (pow(A[0],2) + pow(A[1],2) == pow(A[2],2)) cout << "right" << endl;
		else cout << "wrong"<<endl;
	}
}
/*
int main() {
	int A[3];
	pita(A);
	return 0;
}*/