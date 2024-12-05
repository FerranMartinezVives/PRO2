#ifndef CONJ_CAT_HH
#define CONJ_CAT_HH

#include<iostream>
#include<vector>
using namespace std;

class Conj_Cat {

private:
    
    
    
public:
    //Constructores:
    
    Conj_Cat();
    //Pre: cert
    //Post: vector de un string i 4 nivells com a màxim
    
    Conj_Cat(int num_cat, int max_niv);
    //Pre: num_cat >= 1, max_niv >= 4
    //Post: vector de num_cat strings i max_niv nivells com a màxim
    
    //Destructora:
    
    ~Conj_Cat();
    
    //Modificadores:
    
    void llegir_punts();
    //Pre: 
    //Post: 
    
};
#endif
