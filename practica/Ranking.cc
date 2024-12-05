/** @file Ranking.cc
    @brief Codi de la classe Ranking
*/
#include"Ranking.hh"
using namespace std;

Ranking::Ranking() {
  llista = map<string, Jugador>();
  ranking = vector< map<string, Jugador>::iterator >(0);
}

Ranking::Ranking(int num_jgds) {
  llista = map<string, Jugador>();
  ranking = vector< map<string, Jugador>::iterator >(0);
  for (int i = 0; i < num_jgds; ++i) {
    string n;
    cin >> n;
    Jugador j(n);
    pair< map<string, Jugador>::iterator, bool > p;
    p = llista.insert(make_pair(n, j));
    ranking.push_back(p.first);
  }
}

Ranking::~Ranking() {}

bool Ranking::alta_jugador(const string& p) {
  map<string, Jugador>::iterator it = llista.find(p);
  if (it != llista.end()) return false;
  Jugador j(p);
  pair< map<string, Jugador>::iterator, bool > pair;
  pair = llista.insert(make_pair(p, j));
  ranking.push_back(pair.first);
  return true;
}

bool Ranking::baixa_jugador(const string& j) {
  map<string, Jugador>::iterator it = llista.find(j);
  if (it == llista.end()) return false;
  bool found = false;
  int i = 0;
  while (not found and i < ranking.size()) {
    if (ranking[i] == it) found = true;
    else ++i;
  }
  while (i < ranking.size() - 1) {
    map<string, Jugador>::iterator aux = ranking[i];
    ranking[i] = ranking[i + 1];
    ranking[i + 1] = aux;
    ++i;
  }
  ranking.pop_back();
  llista.erase(it);
  return true;
}

void Ranking::ordenar_ranking() {
  stable_sort(ranking.begin(), ranking.end(), ordre_ranking);
}

void Ranking::actualitzar_partits(const string& j, const pair<int, int>& partits) {
  map<string, Jugador>::iterator it = llista.find(j);
  it->second.augmentar_partits(partits);
}

void Ranking::actualitzar_sets(const string& j, const pair<int, int>& sets) {
  map<string, Jugador>::iterator it = llista.find(j);
  it->second.augmentar_sets(sets);
}

void Ranking::actualitzar_jocs(const string& j, const pair<int, int>& jocs) {
  map<string, Jugador>::iterator it = llista.find(j);
  it->second.augmentar_jocs(jocs);
}

void Ranking::actualitzar_punts(const string& j, int x) {
  map<string, Jugador>::iterator it = llista.find(j);
  if (it != llista.end()) it->second.modificar_puntuacio(x);
}

void Ranking::actualitzar_tornejos(const string& j, int x) {
  map<string, Jugador>::iterator it = llista.find(j);
  if (it != llista.end()) it->second.augmentar_tornejos(x);
}

int Ranking::mida() {
  return llista.size();
}

string Ranking::buscar_posicio(int x) {
  return ranking[x - 1]->first;
}

void Ranking::imprimeix_ranking() {
  for (int i = 0; i < ranking.size(); ++i) {
    cout << i + 1 << " " << ranking[i]->first << " ";
    cout << ranking[i]->second.consultar_puntuacio() << endl;
  }
}

void Ranking::imprimeix_jugadors() {
  map<string, Jugador>::iterator it = llista.begin();
  while (it != llista.end()) {
    cout << it->first << " Rk:";
    int i = 0;
    bool found = false;
    while (not found and i < ranking.size()) {
      if (it == ranking[i]) found = true;
      else ++i;
    }
    cout << i + 1 << " ";
    it->second.imprimeix_estadistiques();
    cout << endl;
    ++it;
  }
}

bool Ranking::imprimeix_jugador(const string& j) {
  map<string, Jugador>::iterator it = llista.find(j);
  if (it == llista.end()) return false;
  int i = 0;
  bool found = false;
  while (not found and i < ranking.size()) {
    if (it == ranking[i]) found = true;
    else ++i;
  }
  cout << j << " Rk:" << i + 1 << " ";
  it->second.imprimeix_estadistiques();
  cout << endl;
  return true;
}

bool Ranking::ordre_ranking(const map<string, Jugador>::iterator& it1, const map<string, Jugador>::iterator& it2) {
  return it1->second.consultar_puntuacio() > it2->second.consultar_puntuacio();
}
