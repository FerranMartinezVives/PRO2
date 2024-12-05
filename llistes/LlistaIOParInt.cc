#include "LlistaIOParInt.hh"

void llegir_llista_ParInt(list<ParInt>& l){
    list<ParInt>::iterator it = l.end();
    ParInt x;
    while (x.llegir()) {
        l.insert(it, x);
    }
}

void escriure_llista_ParInt(const list<ParInt>& l) {
    if (not l.empty()) {
        list<ParInt>::const_iterator it;
        cout << "[Primero]" << endl;
        for (it = l.begin(); it != l.end(); ++it){
            cout << (*it).primer() << " " << (*it).segon() << endl;
        }
        cout << "[Ultimo]";
    } 
    cout << endl;
}
