#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

int main() {
    //Ãâ·Â½Ã°£ ºü¸£°Ô ÇØÁÖ´Â..
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        string input;
        getline(cin, input);

        if (input == ".")  break;

        stack<char> s;
        bool flag = true;
        for (int i = 0; i < input.length(); i++) {
            char c = input[i];

            if ((c == '(') || (c == '[')) {
                s.push(c);
            }
            if (c == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
            if (c == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
        }

        if (flag == true && s.empty())   cout << "yes" << endl;
        else                             cout << "no" << endl;
    }
}
