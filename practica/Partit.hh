/** @file Partit.hh
    @brief Especificació de la classe Partit
*/
#ifndef PARTIT_HH
#define PARTIT_HH

#ifndef NO_DIAGRAM
#include<iostream>
#include<vector>
#endif
using namespace std;

class Partit {

private:

  string resultats;

  pair<int, int> p_a;
  pair<int, int> p_b;
  pair<int, int> s_a;
  pair<int, int> s_b;
  pair<int, int> j_a;
  pair<int, int> j_b;

  int a;
  int b;

  /** @brief Retorna si el jugador <em>b</em> ha guanyat al jugador <em>a</em>
      \pre el paràmetre implícit està inicialitzat completament
      \post retorna cert en cas que <em>b</em> hagi guanyat el partit, i fals altrament
  */
  bool upset();

public:

  //Constructores:

  /** @brief Constructora per defecte
      \pre cert
      \post el paràmetre implícit és un partit que no s'ha realitzat
  */
  Partit();

  /** @brief Constructora a partir del resultat d'un partit, representat per <em>s</em>
      \pre <em>s.size()</em> és 3, 7 o 11, i les seves posicions parells contenen caracters numerals
      \post s'ha guardat tota la informació referent al partit entre dos jugadors arbitraris <em>a</em> i <em>b</em>: qui ha guanyat el partit i els sets i jocs guanyats i perduts per cada jugador
  */
  Partit(const string& s);

  //Destructora:

  /** @brief Destructora per defecte
  */
  ~Partit();

  //Modificadores:

  /** @brief Guarda la posició relativa en el rànking del torneig on s'ha disputat el partit del jugador arbitrari <em>a</em>
      \pre <em>x</em> >= 1
      \post s'ha definit <em>x</em> com la posició relativa en el rànking del torneig on s'ha disputat el partit del jugador <em>a</em>
  */
  void escriure_a(int x);

  /** @brief Guarda la posició relativa en el rànking del torneig on s'ha disputat el partit del jugador arbitrari <em>b</em>
      \pre <em>x</em> >= 1
      \post s'ha definit <em>x</em> com la posició relativa en el rànking del torneig on s'ha disputat el partit del jugador <em>b</em>
  */
  void escriure_b(int x);

  //Consultores:

  /** @brief Retorna la posició relativa en el rànking del torneig on s'ha disputat el partit del guanyador del partit
      \pre les posicions relatives dels dos jugadors del partit han estat definides
      \post retorna la posició relativa en el rànking del torneig on s'ha disputat el partit del guanyador del partit
  */
  int consultar_guanyador();

  /** @brief Retorna la posició relativa en el rànking del torneig on s'ha disputat el partit del perdedor del partit
      \pre les posicions relatives dels dos jugadors del partit han estat definides
      \post retorna la posició relativa en el rànking del torneig on s'ha disputat el partit del perdedor del partit
  */
  int consultar_perdedor();

  /** @brief Retorna la posició relativa en el rànking del torneig on s'ha disputat el partit del jugador <em>a</em>
      \pre la posició relativa del jugador <em>a</em> ha estat definida
      \post retorna la posició relativa en el rànking del torneig on s'ha disputat el partit del jugador <em>a</em>
  */
  int consultar_a();

  /** @brief Retorna la posició relativa en el rànking del torneig on s'ha disputat el partit del jugador <em>b</em>
      \pre la posició relativa del jugador <em>b</em> ha estat definida
      \post retorna la posició relativa en el rànking del torneig on s'ha disputat el partit del jugador <em>b</em>
  */
  int consultar_b();

  /** @brief Retorna un string representant el resultat del partit
      \pre cert
      \post retorna un string representant el resultat del partit
  */
  string consultar_resultats();

  /** @brief Retorna els partits guanyats i perduts del jugador <em>a</em>
      \pre el paràmetre implícit està inicialitzat
      \post retorna un parell d'enters representant els partits guanyats i perduts del jugador <em>a</em>
  */
  pair<int, int> consultar_partits_a();

  /** @brief Retorna els partits guanyats i perduts del jugador <em>b</em>
      \pre el paràmetre implícit està inicialitzat
      \post retorna un parell d'enters representant els partits guanyats i perduts del jugador <em>b</em>
  */
  pair<int, int> consultar_partits_b();

  /** @brief Retorna els sets guanyats i perduts del jugador <em>a</em>
      \pre el paràmetre implícit està inicialitzat
      \post retorna un parell d'enters representant els sets guanyats i perduts del jugador <em>a</em>
  */
  pair<int, int> consultar_sets_a();

  /** @brief Retorna els sets guanyats i perduts del jugador <em>b</em>
      \pre el paràmetre implícit està inicialitzat
      \post retorna un parell d'enters representant els sets guanyats i perduts del jugador <em>b</em>
  */
  pair<int, int> consultar_sets_b();

  /** @brief Retorna els jocs guanyats i perduts del jugador <em>a</em>
      \pre el paràmetre implícit està inicialitzat
      \post retorna un parell d'enters representant els jocs guanyats i perduts del jugador <em>a</em>
  */
  pair<int, int> consultar_jocs_a();

  /** @brief Retorna els jocs guanyats i perduts del jugador <em>b</em>
      \pre el paràmetre implícit està inicialitzat
      \post retorna un parell d'enters representant els jocs guanyats i perduts del jugador <em>b</em>
  */
  pair<int, int> consultar_jocs_b();

};
#endif
