#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;

void router(queue<int>& buffer, int N) {
	int packet;
	cin >> packet;
	while (packet != -1) {
		
		if (packet == 0) {
			if (!buffer.empty()) buffer.pop();
		}
		else if (buffer.size() < N) buffer.push(packet);
		cin >> packet;
	}
}

void print_buffer(queue<int>& buffer) {
	if (buffer.empty()) cout << "empty"; 
	return;
	while (!buffer.empty()) {
		cout << buffer.front()<<" ";
		buffer.pop();
	}
}

/*
int main() {
	int N;
	cin >> N;
	queue<int> buffer;
	
	router(buffer, N);
	print_buffer(buffer);

	return 0;
}
*/