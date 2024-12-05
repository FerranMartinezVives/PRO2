#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> s;
    for (int i = 0; i < n / 2; ++i) {
        int x;
        cin >> x;
        s.push(x);
    }
    int i = 0;
    bool error = false;
    bool odd = false;
    if (n % 2 != 0) odd = true;
    while (not error and i < n / 2) {
        int x;
        cin >> x;
        if (odd) odd = false;
        else if (x != s.top()) error = true;
        else {
            s.pop();
            ++i;
        }
    }
    if (error) cout << "NO" << endl;
    else cout << "SI" << endl;
}
