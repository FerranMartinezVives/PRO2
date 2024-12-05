#include "LlistaIOEstudiant.hh"
using namespace std;

int main() {
    list<Estudiant> l;
    llegir_llista_Estudiant(l);
    int dni;
    cin >> dni;
    list<Estudiant>::const_iterator it;
    int count = 0;
    for (it = l.begin(); it != l.end(); ++it) {
        if ((*it).consultar_DNI() == dni) ++count;
    }
    cout << dni << " " << count << endl;
}
