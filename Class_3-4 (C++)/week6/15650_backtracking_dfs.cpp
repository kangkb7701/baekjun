#include <iostream>
#include <vector>

using namespace std;

vector<int> answ;

void backtracking(int n, int m, int last) {
    if (answ.size() == m) {
        for (int i = 0; i < m; i++) {
            cout << answ[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = last + 1; i <= n; i++) {
        answ.push_back(i);
        //cout << i << " "<<"\n";
        backtracking(n, m, i);
        answ.pop_back();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    backtracking(n, m, 0);
    return 0;
}