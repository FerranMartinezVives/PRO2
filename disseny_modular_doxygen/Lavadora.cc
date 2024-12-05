#include "Lavadora.hh"
using namespace std;

Lavadora::Lavadora() {
    pes = 0;
    ini = false;
}

void Lavadora::inicializar(int pmax, bool col) {
    pes = 0;
    pesmax = pmax;
    this->col = col;
    ini = true;
}

void Lavadora::anadir_prenda(const Prenda& p) {
    list<Prenda>::iterator it = prendas.end();
    prendas.insert(it, p);
}

void Lavadora::lavado() {
    prendas.clear();
    pes = 0;
    ini = false;
}

bool Lavadora::esta_inicializada() {
    return ini;
}

bool Lavadora::consultar_color() {
    return col;
}

int Lavadora::consultar_peso() {
    return pes;
}

int Lavadora::consultar_peso_máximo() {
    return pesmax;
}

void Lavadora::escribir() const {
    list<Prenda>::const_iterator it;
    for (it = l.begin(); it != l.end; ++it) {
        (*it).escribir();
    }
}
