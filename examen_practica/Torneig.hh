/** @file Torneig.hh
    @brief Especificació de la classe Torneig
*/
#ifndef TORNEIG_HH
#define TORNEIG_HH

#include"Ranking.hh"
#include"Partit.hh"
#include"Conjunt_Categories.hh"
#ifndef NO_DIAGRAM
#include<iostream>
#include"BinTree.hh"
#endif
using namespace std;

class Torneig {

private:

    string nom;
    int cat;
    bool iniciat;
    vector< pair<string, int> > actuals;
    vector< pair<string, int> > anteriors;
    BinTree<int> emparellaments;
    BinTree<Partit> resultats;

    /** @brief Retorna l'arbre d'emparellaments entre els <em>n</em> jugadors inscrits
        \pre 1 <= <em>a</em> <= n, 8 <= <em>n</em> <= 2^(<em>k</em> - 1), on <em>k</em> és el nombre màxim de nivells per categoria,
        <em>z</em> = 2^(<em>l</em>), on <em>l</em> és el nivell de l'arbre on es troba l'arrel del subarbre actual
        \post retorna l'arbre d'emparellaments entre els jugadors de rànking relatiu entre <em>a</em> i <em>n</em>
    */
    BinTree<int> generar_arbre_emparellaments(int a, int n, int z);

    /** @brief Imprimeix recursivament en preordre l'arbre d'emparellaments entre els jugadors actualment inscrits
        \pre <em>arbre</em> té com arrel el rànking relatiu del jugador inscrit a imprimir, <em>blank</em> indica si s'ha d'imprimir un espai en blanc
        \post s'ha imprès al canal de sortida el rànking relatiu i el nom del jugador de l'arrel de <em>arbre</em>
    */
    void imprimir_arbre_emparellaments(const BinTree<int>& arbre, bool& blank);

    /** @brief Llegeix recursivament els resultats de tots els partits disputats com un arbre en preordre, i en guarda la informació
        \pre al canal d'entrada hi ha o bé el resultat d'un partit o bé un "0", que indica que el partit no existeix
        \post retorna un arbre amb la informació referent a cada partit llegit
    */
    BinTree<Partit> generar_arbre_resultats(const BinTree<int>& a);

    /** @brief Imprimeix recursivament en preordre els jugadors enfrentats i el resultat de cada partit com un arbre en preordre
        \pre <em>arbre</em> conté a la seva arrel la informació d'un partit disputat al torneig, <em>first</em> indica si l'arrel de l'arbre conté la informació de la final
        \post s'han imprès els jugadors enfrentats i el resultat del partit de l'arrel de <em>arbre</em>
    */
    void imprimir_arbre_resultats(const BinTree<Partit>& arbre, bool first);

    /** @brief Actualitza recursivament les estadístiques dels jugadors participants i els assigna els punts que els corresponen segons la seva posició final
        \pre el paràmetre implícit està iniciat i s'han llegit els resultats de l'edició actual, <em>arbre</em> no és buit, <em>l</em> representa el nivell de l'arbre
        \post s'han actualitzat les estadístiques i assignat els punts corresponents als jugadors enfrentats al partit de l'arrel de <em>arbre</em>
    */
    void assignar_punts(const BinTree<Partit>& arbre, Conjunt_Categories& categories, Ranking& ranking, int l);

public:

    //Constructores:

    /** @brief Constructora per defecte
        \pre cert
        \post el paràmetre implícit té nom buit, la seva categoria és 0, i no està iniciat
    */
    Torneig();

    /** @brief Constructora a partir d'un nom i una categoria
        \pre <em>t</em> no és buit, <em>c</em> >= 1
        \post el paràmetre implícit té nom <em>t</em>, categoria <em>c</em>, i no està iniciat
    */
    Torneig(const string& t, int c);

    //Destructora:

    /** @brief Destructora per defecte
    */
    ~Torneig();

    //Modificadores:

    /** @brief Inicia el paràmetre implícit i imprimeix els emparellaments entre els jugadors inscrits
        \pre el paràmetre implícit no està iniciat, 8 <= <em>n</em> <= 2^(<em>k</em> - 1), on <em>k</em> és el nombre màxim de nivells per categoria,
        al canal d'entrada hi ha <em>n</em> enters representant les posicions en el rànking dels jugadors de <em>ranking</em> que s'inscriuran al torneig
        \post s'ha iniciat el torneig i s'han imprès al canal de sortida els emparellaments entre els jugadors inscrits,
        s'ha guardat la puntuació que van aconseguir els jugadors inscrits a l'edició anterior,
        i s'ha inicialitzat la puntuació dels jugadors inscrits a l'edició actual a 0
    */
    void iniciar(Ranking& ranking, int n);

    /** @brief Llegeix els resultats del torneig com un arbre en preordre, imprimeix qui s'ha enfrentat i els resultats de cada partit,
        i assigna els punts corresponents a cada jugador segons els resultats de l'edició actual i els punts obtinguts l'edició anterior
        \pre el paràmetre implícit està iniciat, al canal d'entrada hi ha els resultats dels partits del torneig representats com un arbre en preordre
        \post s'han imprès els resultats de cada partit disputat al torneig i la puntuació aconseguida per cada jugador participant,
        i s'han assignat els punts corresponents a cada jugador segons els resultats de l'edició actual i l'edició anterior
    */
    void finalitzar(Ranking& ranking, Conjunt_Categories& categories);

    /** @brief Resta la puntuació guanyada de tots els jugadors participants a l'edició anterior
        \pre el paràmetre implícit no està iniciat
        \post s'ha restat la puntuació guanyada de tots els jugadors participants a l'edició anterior del torneig
    */
    void esborrar_punts(Ranking& ranking);

    /** @brief Busca si el jugador amb nom <em>j</em> ha participat al torneig i, en cas afirmatiu, esborra la seva puntuació del registre
        \pre <em>j</em> no és buit, el paràmetre implícit no està iniciat
        \post si hi era, s'ha esborrat el registre de la puntuació del jugador amb nom <em>j</em>
    */
    void esborrar_jugador(const string& j);

    //Consultores:

    bool consultar_iniciat();

    bool consultar_estat();

    /** @brief Retorna el nom del paràmetre implícit
        \pre cert
        \post retorna el nom del paràmetre implícit
    */
    string consultar_nom();

    /** @brief Retorna la categoria del paràmetre implícit
        \pre cert
        \post retorna la categoria del paràmetre implícit
    */
    int consultar_categoria();

    void imprimir_resultats();

};
#endif
