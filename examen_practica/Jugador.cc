/** @file Jugador.cc
    @brief Codi de la classe Jugador
*/
#include"Jugador.hh"
using namespace std;

Jugador::Jugador() {
  nom = "";
  puntuacio = 0;
  tornejos_disputats = 0;
  partits = make_pair(0, 0);
  sets = make_pair(0, 0);
  jocs = make_pair(0, 0);
}

Jugador::Jugador(const string& n) {
  nom = n;
  puntuacio = 0;
  tornejos_disputats = 0;
  partits = make_pair(0, 0);
  sets = make_pair(0, 0);
  jocs = make_pair(0, 0);
}

Jugador::~Jugador() {}

void Jugador::modificar_puntuacio(int x) {
  puntuacio = puntuacio + x;
}

void Jugador::augmentar_tornejos(int n) {
  tornejos_disputats += n;
}

void Jugador::augmentar_partits(const pair<int, int>& p) {
  partits.first += p.first;
  partits.second += p.second;
}

void Jugador::augmentar_sets(const pair<int, int>& p) {
  sets.first += p.first;
  sets.second += p.second;
}

void Jugador::augmentar_jocs(const pair<int, int>& p) {
  jocs.first += p.first;
  jocs.second += p.second;
}

string Jugador::consultar_nom() {
  return nom;
}

int Jugador::consultar_puntuacio() {
  return puntuacio;
}

void Jugador::imprimeix_estadistiques() {
  cout << "Ps:" << puntuacio << " Ts:" << tornejos_disputats;
  cout << " WM:" << partits.first << " LM:" << partits.second;
  cout << " WS:" << sets.first << " LS:" << sets.second;
  cout << " WG:" << jocs.first << " LG:" << jocs.second;
}

double Jugador::percentatge_sets_guanyats() {
  double suma_sets = sets.first + sets.second;
  if (suma_sets == 0) return 0;
  else return (sets.first / suma_sets) * 100.0;
}
