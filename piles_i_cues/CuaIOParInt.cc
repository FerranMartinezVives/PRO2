#include "CuaIOParInt.hh"
#include "ParInt.hh"

void llegirCuaParInt(queue<ParInt>& c) {
    ParInt x;
    bool keep = x.llegir();
    while (keep) {
        c.push(x);
        keep = x.llegir();
    }
}

void escriureCuaParInt(queue<ParInt> c) {
    while (not c.empty()) {
        c.front().escriure();
        c.pop();
    }
}
