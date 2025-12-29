#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    string s;
    int count = 0;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b; // 크기를 미리 지정할 필요 없음

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (binary_search(a.begin(), a.end(), s)) {
            b.push_back(s);
            count++;
        }
    }

    sort(b.begin(), b.end());
    cout << count << "\n";
    for (string s : b)cout << s<<"\n";
    return 0;
}