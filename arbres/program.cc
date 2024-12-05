#include "BinTreeIOParInt.hh"
using namespace std;

void busqueda(const BinTree<ParInt>& a, int n, int prof, bool& found) {
    if (not a.empty()) {
        ParInt x = a.value();
        if (not found) busqueda(a.left(), n, prof + 1, found);
        if (x.primer() == n) {
            cout << n << " " << x.segon() << " " << prof << endl;
            found = true;
        }
        if (not found) busqueda(a.right(), n, prof + 1, found);
    }
}

int main() {
    BinTree<ParInt> a;
    read_bintree_parint(a);
    int n;
    while (cin >> n) {
        bool found = false;
        busqueda(a, n, 0, found);
        if (not found) cout << -1 << endl;
    }
}
