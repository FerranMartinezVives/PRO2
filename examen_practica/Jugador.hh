/** @file Jugador.hh
    @brief Especificació de la classe Jugador
*/
#ifndef JUGADOR_HH
#define JUGADOR_HH

#ifndef NO_DIAGRAM
#include<iostream>
#include<list>
#include<map>
#endif
using namespace std;

class Jugador {

private:

    string nom;
    int puntuacio;
    int tornejos_disputats;
    pair<int, int> partits;
    pair<int, int> sets;
    pair<int, int> jocs;

public:

    //Constructores:

    /** @brief Constructora per defecte
        \pre cert
        \post el paràmetre implícit té nom buit, una puntuació de 0 i totes les estadístiques a 0
    */
    Jugador();

    /** @brief Constructora a partir d'un nom
        \pre <em>n</em> no és buit
        \post el paràmetre implícit té nom <em>n</em>, puntuació de 0 i totes les estadístiques a 0
    */
    Jugador(const string& n);

    //Destructora:

    /** @brief Destructora per defecte
    */
    ~Jugador();

    //Modificadores:

    /** @brief Modifica la puntuació del paràmetre implícit segons el valor de <em>x</em>
        \pre <em>x</em> està inicialitzat
        \post la puntuació del paràmetre implícit s'ha modificat segons el valor de <em>x</em>
    */
    void modificar_puntuacio(int x);

    /** @brief Augmenta l'estadística "tornejos disputats" del paràmetre implícit en <em>n</em>
        \pre <em>n</em> >= 0
        \post l'estadístíca "tornejos disputats" del paràmetre implícit augmenta en <em>n</em>
    */
    void augmentar_tornejos(int n);

    /** @brief Augmenta les estadístiques "partits guanyats" i "partits perduts" del paràmetre implícit segons els valors de <em>p</em>
        \pre <em>p.first</em> >= 0, <em>p.second</em> >= 0
        \post l'estadística "partits guanyats" del paràmetre implícit augmenta en <em>p.first</em>, i l'estadística "partits perduts" augmenta en <em>p.second</em>
    */
    void augmentar_partits(const pair<int, int>& p);

    /** @brief Augmenta les estadístiques "sets guanyats" i "sets perduts" del paràmetre implícit segons els valors de <em>p</em>
        \pre <em>p.first</em> >= 0, <em>p.second</em> >= 0
        \post l'estadística "sets guanyats" del paràmetre implícit augmenta en <em>p.first</em>, i l'estadística "sets perduts" augmenta en <em>p.second</em>
    */
    void augmentar_sets(const pair<int, int>& p);

    /** @brief Augmenta les estadístiques "jocs guanyats" i "jocs perduts" del paràmetre implícit segons els valors de <em>p</em>
        \pre <em>p.first</em> >= 0, <em>p.second</em> >= 0
        \post l'estadística "jocs guanyats" del paràmetre implícit augmenta en <em>p.first</em>, i l'estadística "jocs perduts" augmenta en <em>p.second</em>
    */
    void augmentar_jocs(const pair<int, int>& p);

    //Consultores:

    /** @brief Retorna el nom del paràmetre implícit
        \pre cert
        \post retorna el nom del paràmetre implícit
    */
    string consultar_nom();

    /** @brief Retorna la puntuació del paràmetre implícit
        \pre cert
        \post retorna la puntuació del paràmetre implícit
    */
    int consultar_puntuacio();

    /** @brief Imprimeix la puntuació i totes les estadístiques sobre el paràmetre implícit
        \pre cert
        \post s'han imprès al canal de sortida la puntuació i totes les estadístiques del paràmetre implícit
    */
    void imprimeix_estadistiques();

    double percentatge_sets_guanyats();

};
#endif
