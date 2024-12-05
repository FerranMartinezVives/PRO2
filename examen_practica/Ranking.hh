/** @file Ranking.hh
    @brief Especificació de la classe Ranking
*/
#ifndef RANKING_HH
#define RANKING_HH

#include"Jugador.hh"
#ifndef NO_DIAGRAM
#include<map>
#include<list>
#include<vector>
#include<algorithm>
#endif
using namespace std;

class Ranking {

private:

    map<string, Jugador> llista;
    vector< map<string, Jugador>::iterator > ranking;

    /** @brief Retorna cert si la puntuació del jugador apuntat per <em>it1</em> és major que la del jugador apuntat per <em>it2</em>, fals altrament
        \pre <em>it1</em> i <em>it2</em> apunten a jugadors de la llista del paràmetre implícit
        \post retorna cert si la puntuació del jugador apuntat per <em>it1</em> és major que la del jugador apuntat per <em>it2</em>, fals altrament
    */
    static bool ordre_ranking(const map<string, Jugador>::iterator& it1, const map<string, Jugador>::iterator& it2);

public:

    //Constructores:

    /** @brief Constructora per defecte
        \pre cert
        \post el paràmetre implícit té un rànking i una llista de jugadors buits
    */
    Ranking();

    /** @brief Constructora a partir del nombre de jugadors
        \pre <em>num_jgds</em> >= 0, al canal d'entrada hi ha <em>num_jgds</em> strings no repetits
        \post el paràmetre implícit té un rànking i una llista ordenada alfabèticament de jugadors creats a partir dels strings del canal d'entrada, tots amb puntuació i estadístiques a 0
    */
    Ranking(int num_jgds);

    //Destructora:

    /** @brief Destructora per defecte
    */
    ~Ranking();

    //Modificadores:

    /** @brief Afegeix un amb nom <em>p</em> jugador al rànking i la llista del paràmetre implícit
        \pre <em>p</em> no és buit
        \post si no hi ha cap jugador amb nom <em>p</em> a la llista/rànking,
        s'afegeix un jugador al rànking i la llista amb nom <em>p</em> i puntuació i estadístiques a 0 de tal manera que segueixen ordenats, i retorna cert, altrament retorna fals
    */
    bool alta_jugador(const string& p);

    /** @brief Esborra del rànking i la llista del paràmetre implícit el jugador amb nom <em>j</em>
        \pre <em>j</em> no és buit
        \post si hi ha un jugador amb nom <em>j</em> a la llista/rànking, s'elimina aquest jugador tant del rànking com la llista i retorna cert, altrament retorna fals
    */
    bool baixa_jugador(const string& j);

    /** @brief Ordena en ordre creixent de puntuació els jugadors del rànking
        \pre cert
        \post s'ha ordenat el rànking en ordre creixent de puntuació dels jugadors
    */
    void ordenar_ranking();

    /** @brief Actualitza les estadítiques "partits guanyats" i "partits perduts" del jugador amb nom <em>j</em>
        \pre hi ha un únic jugador amb nom <em>j</em> al rànking del paràmetre implícit,
        <em>partits</em> té com a primer i segon elements el número de partits guanyats i perduts a afegir a les estadístiques del jugador <em>j</em> respectivament
        \post s'han actualitzat les estadístiques "partits guanyats" i "partits perduts" del jugador amb nom <em>j</em> segons els valors de <em>partits</em>
    */
    void actualitzar_partits(const string& j, const pair<int, int>& partits);

    /** @brief Actualitza les estadítiques "sets guanyats" i "sets perduts" del jugador amb nom <em>j</em>
        \pre hi ha un únic jugador amb nom <em>j</em> al rànking del paràmetre implícit,
        <em>sets</em> té com a primer i segon elements el número de sets guanyats i perduts a afegir a les estadístiques del jugador <em>j</em> respectivament
        \post s'han actualitzat les estadístiques "sets guanyats" i "sets perduts" del jugador amb nom <em>j</em> segons els valors de <em>sets</em>
    */
    void actualitzar_sets(const string& j, const pair<int, int>& sets);

    /** @brief Actualitza les estadítiques "jocs guanyats" i "jocs perduts" del jugador amb nom <em>j</em>
        \pre hi ha un únic jugador amb nom <em>j</em> al rànking del paràmetre implícit,
        <em>jocs</em> té com a primer i segon elements el número de jocs guanyats i perduts a afegir a les estadístiques del jugador <em>j</em> respectivament
        \post s'han actualitzat les estadístiques "jocs guanyats" i "jocs perduts" del jugador amb nom <em>j</em> segons els valors de <em>sets</em>
    */
    void actualitzar_jocs(const string& j, const pair<int, int>& jocs);

    /** @brief Actualitza la puntuació del jugador amb nom <em>j</em> segons el valor de <em>x</em>
        \pre <em>j</em> no és buit i <em>x</em> està inicialitzat amb un valor
        \post s'han actualitzat la puntuació del jugador amb nom <em>j</em>
    */
    void actualitzar_punts(const string& j, int x);

    /** @brief Augmenta l'estadística "tornejos disputats" del jugador amb nom <em>j</em> segons el valor de <em>x</em>
        \pre <em>j</em> no és buit, <em>x</em> >= 0
        \post s'ha actualitzat l'estadística "tornejos disputats" del jugador amb nom <em>j</em> segons el valor de <em>x</em>
    */
    void actualitzar_tornejos(const string& j, int x);

    //Consultores:

    /** @brief Retorna el número de jugadors que conté la llista/rànking del paràmetre implícit
        \pre cert
        \post retorna el número de jugadors que conté la llista/rànking del paràmetre implícit
    */
    int mida();

    /** @brief Retorna el nom del jugador a la posició x del rànking
        \pre <em>x</em> <= mida del rànking paràmetre implícit
        \post retorna el nom del jugador a la posició x del rànking
    */
    string buscar_posicio(int x);

    /** @brief Imprimeix en ordre la posició en el rànking, el nom i la puntuació de tots els jugadors
        \pre cert
        \post s'ha imprès al canal de sortida, en ordre, la posició en el rànking, el nom i la puntuació de tots els jugadors del rànking del paràmetre implícit
    */
    void imprimeix_ranking();

    /** @brief Imprimeix per ordre alfabètic el nom, la posició en el rànking, la puntuació i totes les estadístiques dels jugadors de la llista del paràmetre implícit
        \pre cert
        \post s'ha imprès al canal de sortida per ordre alfabètic el nom, la posició en el rànking, la puntuació i totes les estadístiques dels jugadors de la llista
    */
    void imprimeix_jugadors();

    /** @brief Imprimeix el nom, la posició en el rànking, la puntuació i totes les estadístiques del jugador amb nom <em>j</em>
        \pre <em>j</em> no és buit
        \post si a la llista/rànking hi ha un jugador amb nom <em>j</em>, imprimeix al canal de sortida el seu nom, la seva posició en el rànking, la seva puntuació i totes les seves estadístiques, i retorna cert,
        altrament retorna fals
    */
    bool imprimeix_jugador(const string& j);

    void imprimeix_millor_jugador_sets();
};
#endif
