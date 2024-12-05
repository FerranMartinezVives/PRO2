#ifndef TORNEIG_HH
#define TORNEIG_HH

#include<iostream>
using namespace std;

class Torneig {
    
private:
    string nom;
    int cat;
    
public:
    
    //Constructores:
    Torneig();
    //Pre: cert
    //Post: torneig amb nom buit i categoria 0 (?)
    
    Torneig(string nom, int cat);
    //Pre: nom no buit, categoria >= 1
    //Post: torneig amb nom "nom" i categoria "cat"
    
    //Destructora:
    ~Torneig();
    
    //Modificadora:
    
    void mod_torneig(string nom, int cat);
    //Pre: cert
    //Post: el paràmetre implícit passa a tenir nom "nom" i categoria "cat"
    
    
};
#endif
