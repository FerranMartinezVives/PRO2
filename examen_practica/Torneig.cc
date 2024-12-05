/** @file Torneig.cc
    @brief Codi de la classe Torneig
*/
#include"Torneig.hh"
using namespace std;

Torneig::Torneig() {
  nom = "";
  cat = 0;
  iniciat = false;
}

Torneig::Torneig(const string& t, int c) {
  nom = t;
  cat = c;
  iniciat = false;
}

Torneig::~Torneig() {}

void Torneig::iniciar(Ranking& ranking, int n) {
  iniciat = true;
  anteriors = actuals;
  actuals = vector< pair<string, int> >(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    string j = ranking.buscar_posicio(x);
    actuals[i] = make_pair(j, -1);
  }
  emparellaments = generar_arbre_emparellaments(1, n, 2);
  bool blank = false;
  imprimir_arbre_emparellaments(emparellaments, blank);
  cout << endl;
}

void Torneig::finalitzar(Ranking& ranking, Conjunt_Categories& categories) {
  resultats = generar_arbre_resultats(emparellaments);
  assignar_punts(resultats, categories, ranking, 1);
  for (int i = 0; i < anteriors.size(); ++i) ranking.actualitzar_punts(anteriors[i].first, -anteriors[i].second);
  for (int i = 0; i < actuals.size(); ++i) {
    if (actuals[i].second != 0) cout << i + 1 << "." << actuals[i].first << " " << actuals[i].second << endl;
    ranking.actualitzar_punts(actuals[i].first, actuals[i].second);
    ranking.actualitzar_tornejos(actuals[i].first, 1);
  }
  iniciat = false;
}

bool Torneig::consultar_iniciat() {
  return actuals.size() != 0;
}

bool Torneig::consultar_estat() {
  return iniciat;
}

string Torneig::consultar_nom() {
  return nom;
}

int Torneig::consultar_categoria() {
  return cat;
}

void Torneig::imprimir_resultats() {
  imprimir_arbre_resultats(resultats, true);
  cout << endl;
}

BinTree<int> Torneig::generar_arbre_emparellaments(int a, int n, int z) {
  int b;
  if (a % 2 == 0) b = z - a + 2;
  else b = z - a;
  if (b <= n) {
    if (z == 2) return BinTree<int>(a, generar_arbre_emparellaments(1, n, z * 2), generar_arbre_emparellaments(2, n, z * 2));
    else return BinTree<int>(a, generar_arbre_emparellaments(a, n, z * 2), generar_arbre_emparellaments(b, n, z * 2));
  }
  else return BinTree<int>(a);
}

void Torneig::imprimir_arbre_emparellaments(const BinTree<int>& arbre, bool& blank) {
  BinTree<int> e = arbre.left();
  BinTree<int> d = arbre.right();
  if (e.left().empty() and e.right().empty()) {
    if (blank) {
      cout << " ";
      blank = false;
    }
    cout << "(" << e.value() << "." << actuals[e.value() - 1].first << " ";
  }
  else {
    if (blank) {
      cout << " ";
      blank = false;
    }
    cout << "(";
    imprimir_arbre_emparellaments(e, blank);
  }
  if (d.left().empty() and d.right().empty()) {
    cout << d.value() << "." << actuals[d.value() - 1].first << ")";
    blank = true;
  }
  else {
    imprimir_arbre_emparellaments(d, blank);
    cout << ")";
    blank = true;
  }
}

BinTree<Partit> Torneig::generar_arbre_resultats(const BinTree<int>& a) {
  string s;
  cin >> s;
  if (s == "0") return BinTree<Partit>();
  else {
    Partit p(s);
    BinTree<Partit> e = generar_arbre_resultats(a.left());
    BinTree<Partit> d = generar_arbre_resultats(a.right());
    if (e.empty()) p.escriure_a(a.left().value());
    else {
      Partit p_e = e.value();
      p.escriure_a(p_e.consultar_guanyador());
    }
    if (d.empty()) p.escriure_b(a.right().value());
    else {
      Partit p_d = d.value();
      p.escriure_b(p_d.consultar_guanyador());
    }
    return BinTree<Partit>(p, e, d);
  }
}

void Torneig::imprimir_arbre_resultats(const BinTree<Partit>& arbre, bool first) {
  Partit p = arbre.value();
  int a = p.consultar_a();
  int b = p.consultar_b();
  string s = p.consultar_resultats();
  cout << "(" << a << "." << actuals[a - 1].first << " vs " << b << "." << actuals[b - 1].first << " " << s;
  if (not arbre.left().empty()) {
    imprimir_arbre_resultats(arbre.left(), false);
    cout << ")";
  }
  if (not arbre.right().empty()) {
    imprimir_arbre_resultats(arbre.right(), false);
    cout << ")";
  }
  if (first) cout << ")";
}

void Torneig::assignar_punts(const BinTree<Partit>& arbre, Conjunt_Categories& categories, Ranking& ranking, int l) {
  Partit p = arbre.value();
  int a = p.consultar_a();
  int b = p.consultar_b();
  pair<int, int> pair_a = p.consultar_partits_a();
  pair<int, int> pair_b = p.consultar_partits_b();
  ranking.actualitzar_partits(actuals[a - 1].first, pair_a);
  ranking.actualitzar_partits(actuals[b - 1].first, pair_b);
  pair_a = p.consultar_sets_a();
  pair_b = p.consultar_sets_b();
  ranking.actualitzar_sets(actuals[a - 1].first, pair_a);
  ranking.actualitzar_sets(actuals[b - 1].first, pair_b);
  pair_a = p.consultar_jocs_a();
  pair_b = p.consultar_jocs_b();
  ranking.actualitzar_jocs(actuals[a - 1].first, pair_a);
  ranking.actualitzar_jocs(actuals[b - 1].first, pair_b);
  int p_w = p.consultar_guanyador();
  int p_l = p.consultar_perdedor();
  if (actuals[p_w - 1].second == -1) actuals[p_w - 1].second = categories.punts(cat, l);
  actuals[p_l - 1].second = categories.punts(cat, l + 1);
  if (not arbre.left().empty()) assignar_punts(arbre.left(), categories, ranking, l + 1);
  if (not arbre.right().empty()) assignar_punts(arbre.right(), categories, ranking, l + 1);
}

void Torneig::esborrar_punts(Ranking& ranking) {
  for (int i = 0; i < actuals.size(); ++i) ranking.actualitzar_punts(actuals[i].first, -actuals[i].second);
}

void Torneig::esborrar_jugador(const string& j) {
  bool found = false;
  int i = 0;
  while (not found and i < actuals.size()) {
    if (actuals[i].first == j) {
      found = true;
      actuals[i].second = 0;
    }
    else ++i;
  }
}
