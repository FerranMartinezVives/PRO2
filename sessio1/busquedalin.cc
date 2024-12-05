#include <iostream>
#include "vectorIOint.hh"
using namespace std;

/* Buscar  */
int busqueda_lin(const vector<int>& v, int x) {
    /* Pre: cierto */
    /* Post: el resultado indica si x está en v */
    int tam = v.size();
    int i = 0;
    int a = -1; 
    bool b = false;
    while (not b and i < tam) {
        if (v[i] == x) {
            b = true;
            a = i;
        }
        else ++i;
    }
    return a;
}

int main() {
    vector<int> v;
    leer_vector_int(v); 
    cout << "Escribe el elemento a buscar: " << endl;
    int x;
    cin >> x; 
    int a = busqueda_lin(v,x);
    if (a != -1)  cout << "El elemento " << x << " esta en el vector en la posicion " << a + 1 << endl << endl;
    else cout << "El elemento " << x << " no esta en el vector." << endl << endl;
    cout << "Escribimos el vector para que se vea que no ha cambiado:" << endl;
    escribir_vector_int(v);
}
