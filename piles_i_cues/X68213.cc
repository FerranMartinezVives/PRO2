#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void op_1(vector< stack<string> >& v) {
    string s;
    cin >> s;
    int x;
    cin >> x;
    v[x - 1].push(s);
}

void op_2(vector< stack<string> >& v) {
    int s, x;
    cin >> s >> x;
    for (int i = 0; i < s; ++i) v[x - 1].pop();
}

void op_3(vector< stack<string> >& v) {
    int x;
    cin >> x;
    stack<string> s = v[x - 1];
    cout << "Pila de la categoria " << x << endl;
    while (not s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector< stack<string> > v(n);
    int op;
    cin >> op;
    while (op != -4) {
        if (op == -1) op_1(v);
        if (op == -2) op_2(v);
        if (op == -3) op_3(v);
        cin >> op;
    }
}
