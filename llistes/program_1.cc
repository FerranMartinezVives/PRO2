#include "LlistaIOParInt.hh"
using namespace std;

int main() {
    list<ParInt> l;
    llegir_llista_ParInt(l);
    int x;
    cin >> x;
    list<ParInt>::const_iterator it;
    int count = 0;
    int suma = 0;
    for (it = l.begin(); it != l.end(); ++it) {
        if ((*it).primer() == x) {
            ++count;
            suma += (*it).segon();
        }
    }
    cout << x << " " << count << " " << suma << endl;
}
