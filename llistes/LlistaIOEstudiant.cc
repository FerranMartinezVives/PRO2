#include "LlistaIOEstudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l){
    list<Estudiant>::iterator it = l.end();
    Estudiant x;
    x.llegir();
    while (x.consultar_DNI() != 0) {
        l.insert(it, x);
        x.llegir();
    }
}

void EscriureLlistaEstudiant(const list<Estudiant>& l) {
    if (not l.empty()) {
        list<Estudiant>::const_iterator it;
        for (it = l.begin(); it != l.end(); ++it){
            (*it).escriure();
        }
    } 
}
