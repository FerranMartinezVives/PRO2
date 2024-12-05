/**
 * @mainpage Ejemplo de diseño modular:  Gestión de una lavadora.
 
En este ejemplo se construye un programa modular que ofrece un menú de opciones para gestionar una lavadora. Se introducen las clases <em>Lavadora</em>, <em>Cubeta</em> y <em>Prenda</em>.

Sólo se documentan elementos públicos. En una próxima sesión se verá un ejemplo
de proyecto completamente documentado, incluyendo los elementos privados.
*/

/** @file pro2_s8.cc
    @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Prenda.hh"
#include "Lavadora.hh"
#include "Cubeta.hh"
#ifndef NO_DIAGRAM // explicado en Prenda.hh
#include "readbool.hh"
#endif

/** @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/

void ini_lav(Lavadora& lav) {
    int pmax;
    bool col;
    cin >> pmax;
    col = readbool();
    lav.inicializar(pmax, col);
}

void pren_a_lav(Lavadora& lav) {
    int pes;
    bool col;
    cin >> pes;
    col = readbool();
    Prenda p(pes, col);
    lav.anadir_prenda(p);
}

void pren_a_cub(Cubeta& cub) {
    int pes;
    bool col;
    cin >> pes;
    col = readbool();
    Prenda p(pes, col);
    cub.anadir_prenda(p);
}

void compl_lav(Lavadora& lav, Cubeta& cub) {
    cub.completar_lavadora(lav);
}

void lavado(Lavadora& lav) {
    lav.lavado();
}

void esc_cub(Cubeta& cub) {
    cub.escribir();
}

void esc_lav(Lavadora& lav) {
    lav.escribir();
}

int main ()
{
    Lavadora lav;
    Cubeta cub;
    int op;
    cin >> op;
    while (op != -8) {
        if (op == -1) ini_lav(lav);
        else if (op == -2) pren_a_lav(lav);
        else if (op == -3) pren_a_cub(cub);
        else if (op == -4) compl_lav(lav, cub);
        else if (op == -5) lavado(lav);
        else if (op == -6) esc_cub(cub);
        else if (op == -7) esc_lav(lav);
        cin >> op;
    }
}
