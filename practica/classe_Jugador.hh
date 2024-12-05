#ifndef JUGADOR_HH
#define JUGADOR_HH

#include<iostream>
using namespace std;

class Jugador {
private:
    string nom;
    int puntuacio;
    int tornejos;
    int partits_guanyats;
    int partits_perduts;
    int sets_guanyats;
    int sets_perduts;
    int jocs_guanyats;
    int jocs_perduts;
    
public:
    
    //Constructores:
    Jugador();
    //Pre: cert
    //Post: paràmetre implícit amb nom buit i estadístiques a 0
    
    Jugador(string nom);
    //Pre: cert
    //Post: paràmetre implícit amb nom "nom" i estadístiques a 0
    
    //Destructora:
    ~Jugador();
    
    //Modificadores:
    
    void modificar_puntuació(int punts, bool inc-dec);
    //Pre: cert
    //Post: el camp puntuacio del paràmetre implícit que incrementat o decrementat (excepte si puntuacio == 0) en "punts" depenent de si inc-dec és cert o fals
    
    void augmentar_tornejos(int n);
    //Pre: cert
    //Post: el camp tornejos del paràmetre implícit augmenta en n
    
    void augmentar_p_g(int n);
    
    void augmentar_p_p(int n);
    
    void augmentar_s_g(int n);
    
    void augmentar_s_p(int n);
    
    void augmentar_j_g(int n);
    
    void augmentar_j_p(int n);
    
    //Consultores:
    
    
    
};
#endif
