#include "vectorIOEstudiant.hh"
using namespace std;

/* Buscar  */
int busqueda_lin_vest(const vector<Estudiant>& v, int dni) {
    /* Pre: cierto */
    /* Post: el resultado indica si x está en v */
    int tam = v.size();
    int i = 0;
    int a = -1; 
    bool b = false;
    while (not b and i < tam) {
        int x = v[i].consultar_DNI();
        if (x == dni) {
            b = true;
            a = i;
        }
        else ++i;
    }
    return a;
}

int main() {
    vector<Estudiant> v;
    leer_vector_Estudiant(v); 
    cout << "Escribe el estudiante a buscar: " << endl;
    int dni;
    cin >> dni; 
    int a = busqueda_lin_vest(v, dni);
    if (a != -1)  {
        if (not v[a].te_nota()) cout << "El estudiante esta en el vector pero no tiene nota" << endl;
        else cout << "El estudiante esta en el vector y su nota es " << v[a].consultar_nota() << endl;
    }
    else cout << "El estudiante no esta en el vector." << endl;
}
