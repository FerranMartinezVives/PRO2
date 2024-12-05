#ifndef CONJ_TORN_HH
#define CONJ_TORN_HH

#include"Torneig.hh"
#include<vector>
using namespace std;

class Conj_Tornejos {
    
private:
    vector<Torneig> vec_torn;
    
public:
    
    //Constructores:
    
    Conj_Tornejos();
    //Pre: cert
    //Post: vector de tornejos de mida 0
    
    Conj_Tornejos(int t);
    //Pre: t >= 1
    //Post: vector de tornejos de mida t on tots els seus tornejos son buits
    
    //Destructora:
    
    ~Conj_Tornejos();
    
    //Modificadores:
    
    void llegir_tornejos();
    //Pre: al canal d'entrada hi ha tants parells de strings i ints com la mida del vector del paràmetre implícit
    //Post: s'han modificat tots els elements del vector del paràmetre implícit segons els parells del canal d'entrada
    
    
};
