#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> s;
    char c;
    cin >> c;
    bool error = false;
    while (not error and c != '.') {
        if (s.empty()) {
            if (c == ')' or c == ']') error = true;
            else s.push(c);
        }
        else {
            char p = s.top();
            if (c == ')' and p == '(') s.pop();
            else if (c == ']' and p == '[') s.pop();
            else if (c == ')' or c == ']') error = true;
            else s.push(c);
        }
        cin >> c;
    }
    if (not error and s.empty()) cout << "Correcte" << endl;
    else cout << "Incorrecte" << endl;
}
