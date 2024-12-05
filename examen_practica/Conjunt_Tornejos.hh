/** @file Conjunt_Tornejos.hh
    @brief Especificació de la classe Conjunt_Tornejos
*/
#ifndef CONJ_TORN_HH
#define CONJ_TORN_HH

#include"Torneig.hh"
#ifndef NO_DIAGRAM
#include<map>
#include<list>
#include<vector>
#endif
using namespace std;

class Conjunt_Tornejos {

private:

    map<string, Torneig> tour;

public:

    //Constructores:

    /** @brief Constructora per defecte
        \pre cert
        \post el paràmetre implícit és una llista buida de tornejos
    */
    Conjunt_Tornejos();

    /** @brief Constructora a partir del número de tornejos
        \pre <em>num_tjs</em> >= <em>0</em>, al canal d'entrada hi ha <em>num_tjs</em> parells de strings i enters
        \post el paràmetre implícit és una llista ordenada alfabèticament segons els noms dels tornejos representats pels parells del canal d'entrada
    */
    Conjunt_Tornejos(int num_tjs);

    //Destructora:

    /** @brief Destructora per defecte
    */
    ~Conjunt_Tornejos();

    //Modificadores:

    /** @brief Afegeix el torneig <em>tg</em> a la llista de tornejos del paràmetre implícit
        \pre no hi ha cap element a la llista de tornejos del paràmetre implícit que tingui el mateix nom que <em>tg</em>
        \post s'ha afegit <em>tg</em> a la llista de tornejos del paràmetre implícit tal que segueix ordenada
    */
    bool alta_torneig(const string& tg, int c);

    /** @brief Esborra l'element amb nom <em>t</em> de la llista de tornejos del paràmetre implícit
        \pre només hi ha un únic element amb nom <em>t</em> a la llista de tornejos del paràmetre implícit
        \post s'ha esborrat l'element apuntat amb nom <em>t</em> de la llista de tornejos del paràmetre implícit
    */
    bool baixa_torneig(const string& t, Ranking& ranking);

    /** @brief Esborra la puntuació que el jugador <em>j</em> ha aconseguit en tots els tornejos del paràmetre implícit
        \pre <em>j</em> no és buit
        \post s'ha esborrat la puntuació que el jugador <em>j</em> ha aconseguit en tots els tornejos del paràmetre implícit
    */
    void baixa_jugador(const string& j);

    /** @brief Inicia el torneig amb nom <em>t</em> i imprimeix els emparellaments entre els jugadors inscrits
        \pre <em>t</em> és el nom d'un torneig de la llista de tornejos del paràmetre implícit que no està iniciat,
        <em>n</em> és el nombre de jugadors que s'inscriuran al torneig,
        al canal d'entrada hi ha <em>n</em> enters, representant les posicions en el rànking dels jugadors de <em>ranking</em> que s'incriuran al torneig
        \post s'ha iniciat el torneig amb nom <em>t</em> i s'han imprès al canal de sortida els emparellaments entre els jugadors inscrits al torneig
    */
    void iniciar_torneig(const string& t, Ranking& ranking, int n);

    /** @brief Llegeix els resultats del torneig amb nom <em>t</em>, imprimeix l'arbre de partits disputats i assigna els punts corresponents segons els resultats
        \pre <em>t</em> és el nom d'un torneig iniciat del paràmetre implícit
        \post s'ha imprès l'arbre de partits disputats, la puntuació obtinguda pels jugadors participants,
        i s'han assignat les puntuacions corresponents als jugadors participants a l'edició actual i anterior del torneig
    */
    void finalitzar_torneig(const string& t, Ranking& ranking, Conjunt_Categories& categories);

    //Consultores:

    /** @brief Retorna el número de tornejos que conté la llista del paràmetre implícit
        \pre cert
        \post retorna el número de tornejos que conté la llista del paràmetre implícit
    */
    int mida();

    bool buscar_torneig(const string& t);

    bool consultar_iniciat(const string& t);

    bool imprimir_resultats(const string& t);

    /** @brief Retorna la categoria del torneig amb nom <em>t</em>
        \pre la llista de tornejos del paràmetre implícit conté un únic element amb nom <em>t</em>
        \post retorna la categoria del torneig amb nom <em>t</em>
    */
    int consultar_categoria(const string& t);

    /** @brief Imprimeix per ordre alfabètic el nom i la categoria de tots els tornejos de la llista de tornejos del paràmetre implícit
        \pre cert
        \post s'han imprès al canal de sortida el nom i la categoria de tots els tornejos de la llista de tornejos del paràmetre implícit
    */
    void imprimeix_tour(Conjunt_Categories& categories);

};
#endif
