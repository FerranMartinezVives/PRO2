#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        int a;
        int sum = 0;
        cin >> a;
        while (a != x) {
            sum += a;
            cin >> a;
        }
        cout << "La suma de la secuencia " << i << " es " << sum << endl;
        string s;
        getline(cin, s);
    }
}
