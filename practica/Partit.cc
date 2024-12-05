/** @file Partit.cc
    @brief Codi de la classe Partit
*/
#include"Partit.hh"

Partit::Partit() {
  resultats = "";
}

Partit::Partit(const string& s) {
  resultats = s;
  if (s.size() == 3) {
    p_a = make_pair(s[0] - '0', s[2] - '0');
    p_b = make_pair(s[2] - '0', s[0] - '0');
    s_a = s_b = j_a = j_b = make_pair(0, 0);
  }
  else {
    s_a = s_b = j_a = j_b = make_pair(0, 0);
    for (int i = 0; i < s.size(); i += 4) {
      int a = s[i];
      int b = s[i + 2];
      if (a > b) {
        ++s_a.first;
        ++s_b.second;
      }
      else {
        ++s_a.second;
        ++s_b.first;
      }
      j_a.first += a - '0';
      j_a.second += b - '0';
      j_b.first += b - '0';
      j_b.second += a - '0';
    }
    if (s_a.first == 2) {
      p_a = make_pair(1, 0);
      p_b = make_pair(0, 1);
    }
    else {
      p_a = make_pair(0, 1);
      p_b = make_pair(1, 0);
    }
  }
}

Partit::~Partit() {}

void Partit::escriure_a(int x) {
  a = x;
}

void Partit::escriure_b(int x) {
  b = x;
}

bool Partit::upset() {
  return p_a.first < p_a.second;
}

int Partit::consultar_guanyador() {
  if (upset()) return b;
  else return a;
}

int Partit::consultar_perdedor() {
  if (upset()) return a;
  else return b;
}

int Partit::consultar_a() {
  return a;
}

int Partit::consultar_b() {
  return b;
}

string Partit::consultar_resultats() {
  return resultats;
}

pair<int, int> Partit::consultar_partits_a() {
  return p_a;
}

pair<int, int> Partit::consultar_partits_b() {
  return p_b;
}

pair<int, int> Partit::consultar_sets_a() {
  return s_a;
}

pair<int, int> Partit::consultar_sets_b() {
  return s_b;
}

pair<int, int> Partit::consultar_jocs_a() {
  return j_a;
}

pair<int, int> Partit::consultar_jocs_b() {
  return j_b;
}
