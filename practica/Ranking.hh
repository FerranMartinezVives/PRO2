#ifndef RANKING_HH
#define RANKING_HH

#include"Jugador.hh"
#include<list>
using namespace std;

class Ranking {
    
private:
    
    list<Jugador> ranking;
    
public:
    
    //Constructores:
    
    Ranking();
    //Pre: cert
    //Post: el paràmetre implícit és una llista buida de mida 0
    
    Ranking(int num_jug);
    //Pre: al canal d'entrada hi ha num_jug strings
    //Post: el paràmetre implícit és una llista de mida num_jug on els seus elements estan ordenats per l'ordre en què apareixien al canal d'entrada 
    
    //Destructora:
    
    ~Ranking();
    
    //Modificadores:
    
    void alta_jugador(Jugador j);
    //Pre: no hi ha cap element al paràmetre implícit amb el mateix nom que "j", les estadístiques de j estan totes a 0
    //Post: s'ha afegit "j" al final de la llista del paràmetre implícit
    
    void baixa_jugador(list<Jugador>::iterator it);
    //Pre: it està entre l'inici i el final de la llista del paràmetre implícit
    //Post: s'ha esborrat de la llista del paràmetre implícit l'element j apuntat per l'iterador it i els jugadors per sota de j queden una posició per sobre d'on estaven prèviament
    
};
#endif
