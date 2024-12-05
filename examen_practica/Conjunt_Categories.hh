/** @file Conjunt_Categories.hh
    @brief Especificació de la classe Conjunt_Categories
*/
#ifndef CONJ_CAT_HH
#define CONJ_CAT_HH

#ifndef NO_DIAGRAM
#include<iostream>
#include<vector>
#endif
using namespace std;

class Conjunt_Categories {

private:

    vector< vector<int> > taula_punts;
    vector<string> categories;

public:

    //Constructores:

    /** @brief Constructora per defecte
        \pre cert
        \post el paràmetre implícit té una taula de punts i un vector de noms de categories buits
    */
    Conjunt_Categories();

    /** @brief Constructora a partir del número de categories i el número màxim de nivells per categoria
        \pre <em>c</em> >= 1, <em>k</em> >= 1, al canal d'entrada hi ha <em>c</em> strings, seguits de <em>c * k</em> enters majors o iguals que 0
        \post: el vector de noms de les categories té com elements els <em>c</em> strings del canal d'entrada, la taula de punts té <em>c</em> files i <em>k</em> columnes, i els seus elements són els enters que hi havia al canal d'entrada
    */
    Conjunt_Categories(int c, int k);

    //Destructora:

    /** @brief Destructora per defecte
    */
    ~Conjunt_Categories();

    //Consultores:

    /** @brief Retorna el número de categories del paràmetre implícit
        \pre cert
        \post retorna el número de categories del paràmetre implícit
    */
    int num_ctgs();

    /** @brief Retorna el número màxim de nivells per categoria del paràmetre implícit
        \pre cert
        \post retorna el número màxim de nivells per categoria del paràmetre implícit
    */
    int num_nvls();

    /** @brief Retorna els punts corresponents al nivell <em>k</em> de la categoria <em>c</em>
        \pre: 1 <= <em>c</em> <= nombre de categories, 1 <= <em>k</em> <= nombre màxim de nivells
        \post retorna els punts corresponents al nivell <em>k</em> de la categoria <em>c</em>
    */
    int punts(int c, int k);

    /** @brief Retorna un vector amb els noms de les categories del paràmetre implícit, ordenat segons la categoria
        \pre cert
        \post retorna el vector de noms de les categories del paràmetre implícit
    */
    string consultar_nom(int c);

    /** @brief Imprimeix la informació sobre el paràmetre implícit
        \pre cert
        \post s'han imprès al canal de sortida els noms de totes les categories, a més a més de la taula de punts per cada categoria
    */
    void imprimeix_categories();

};
#endif
