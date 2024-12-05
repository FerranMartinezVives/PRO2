/** @file Conjunt_Tornejos.cc
    @brief Codi de la classe Conjunt_Tornejos
*/
#include"Conjunt_Tornejos.hh"
using namespace std;

Conjunt_Tornejos::Conjunt_Tornejos() {
  tour = map<string, Torneig>();
}

Conjunt_Tornejos::Conjunt_Tornejos(int num_tjs) {
  tour = map<string, Torneig>();
  for (int i = 0; i < num_tjs; ++i) {
    string t;
    int c;
    cin >> t >> c;
    Torneig tg(t, c);
    tour.insert(make_pair(t, tg));
  }
}

Conjunt_Tornejos::~Conjunt_Tornejos() {}

bool Conjunt_Tornejos::alta_torneig(const string& t, int c) {
  map<string, Torneig>::iterator it = tour.find(t);
  if (it != tour.end()) return false;
  Torneig tg(t, c);
  tour.insert(make_pair(t, tg));
  return true;
}

bool Conjunt_Tornejos::baixa_torneig(const string& t, Ranking& ranking) {
  map<string, Torneig>::iterator it = tour.find(t);
  if (it == tour.end()) return false;
  else {
    it->second.esborrar_punts(ranking);
    tour.erase(it);
    return true;
  }
}

void Conjunt_Tornejos::baixa_jugador(const string& j) {
  map<string, Torneig>::iterator it = tour.begin();
  while (it != tour.end()) {
    it->second.esborrar_jugador(j);
    ++it;
  }
}

int Conjunt_Tornejos::mida() {
  return tour.size();
}

bool Conjunt_Tornejos::buscar_torneig(const string& t) {
  map<string, Torneig>::iterator it = tour.find(t);
  return it != tour.end();
}

bool Conjunt_Tornejos::consultar_iniciat(const string& t) {
  map<string, Torneig>::iterator it = tour.find(t);
  return it->second.consultar_iniciat();
}

int Conjunt_Tornejos::consultar_categoria(const string& t) {
  map<string, Torneig>::iterator it = tour.find(t);
  return (*it).second.consultar_categoria();
}

bool Conjunt_Tornejos::imprimir_resultats(const string& t) {
  map<string, Torneig>::iterator it = tour.find(t);
  if (it->second.consultar_estat()) return false;
  else {
    it->second.imprimir_resultats();
    return true;
  }
}

void Conjunt_Tornejos::imprimeix_tour(Conjunt_Categories& categories) {
  map<string, Torneig>::iterator it = tour.begin();
  while (it != tour.end()) {
    int c = it->second.consultar_categoria();
    cout << it->first << " " << categories.consultar_nom(c) << endl;
    ++it;
  }
}

void Conjunt_Tornejos::iniciar_torneig(const string& t, Ranking& ranking, int n) {
  map<string, Torneig>::iterator it = tour.find(t);
  (*it).second.iniciar(ranking, n);
}

void Conjunt_Tornejos::finalitzar_torneig(const string& t, Ranking& ranking, Conjunt_Categories& categories) {
  map<string, Torneig>::iterator it = tour.find(t);
  it->second.finalitzar(ranking, categories);
}
