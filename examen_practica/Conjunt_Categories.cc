/** @file Conjunt_Categories.cc
    @brief Codi de la classe Conjunt_Categories
*/
#include"Conjunt_Categories.hh"
using namespace std;

Conjunt_Categories::Conjunt_Categories() {
  taula_punts = vector< vector<int> >(0);
  categories = vector<string>(0);
}

Conjunt_Categories::Conjunt_Categories(int c, int k) {
  categories = vector<string>(c);
  for (int i = 0; i < c; ++i) cin >> categories[i];
  taula_punts = vector< vector<int> >(c, vector<int>(k));
  for (int i = 0; i < c; ++i) {
    for (int j = 0; j < k; ++j) cin >> taula_punts[i][j];
  }
}

Conjunt_Categories::~Conjunt_Categories() {}

int Conjunt_Categories::num_ctgs() {
  return categories.size();
}

int Conjunt_Categories::num_nvls() {
  return taula_punts[0].size();
}

int Conjunt_Categories::punts(int c, int k) {
  return taula_punts[c - 1][k - 1];
}

string Conjunt_Categories::consultar_nom(int c) {
  return categories[c - 1];
}

void Conjunt_Categories::imprimeix_categories() {
  int c = categories.size();
  int k = taula_punts[0].size();
  for (int i = 0; i < c; ++i) {
    cout << categories[i];
    for (int j = 0; j < k; ++j) cout << " " << taula_punts[i][j];
    cout << endl;
  }
}
