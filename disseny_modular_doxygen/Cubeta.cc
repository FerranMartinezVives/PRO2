#include "Cubeta.hh"
using namespace std;

Cubeta::Cubeta() {
    
}

Cubeta::Cubeta(const Cubeta& c) {
    ropacolor = c.ropacolor;
    ropablanca = c.ropablanca;
}

void Cubeta::anadir_prenda(const Prenda& p) {
    if (p.consul_color()) ropacolor.push(p);
    else ropablanca.push(p);
}

void Cubeta::completar_lavadora(Lavadora& lav) {
    bool col = lav.consultar_color();
    if (col) completar_lavadora_pila_it(ropacolor, lav);
    else completar_lavadora_pila_it(ropablanca, lav);
}

void Cubeta::completar_lavadora_pila_it(stack<Prenda>& p, Lavadora& l) {
    int pmax = l.consultar_peso_maximo();
    int peso = l.consultar_peso();
    bool end = false;
    while (not end) {
        if (p.empty()) end = true;
        else if(p.top().consul_peso() + peso > pmax) end = true;
        else {
            l.anadir_prenda(p.top());
            p.pop();
        }
    }
}

void Cubeta::escribir() const {
    escribir_pila_prenda(ropacolor);
    escribir_pila_prenda(ropablanca);
}

void Cubeta::escribir_pila_prenda(const stack<Prenda>& p) {
    stack<Prenda> copia = p;
    while (not copia.empty()) {
        copia.top().escribir();
        copia.pop();
    }
}
