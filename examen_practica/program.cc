/** @file program.cc
    @brief Programa principal per la pràctica de PRO2 de 2022: <em>Circuito de torneos de tenis</em>
*/
#include"Conjunt_Categories.hh"
#include"Conjunt_Tornejos.hh"
#include"Ranking.hh"
#ifndef NO_DIAGRAM
#include<iostream>
#include<list>
#include<vector>
#endif
using namespace std;

int main() {

  int num_cat, max_niv;
  cin >> num_cat >> max_niv;
  Conjunt_Categories categories(num_cat, max_niv);

  int num_tjs;
  cin >> num_tjs;
  Conjunt_Tornejos tour(num_tjs);

  int num_jgds;
  cin >> num_jgds;
  Ranking ranking(num_jgds);

  string comando;
  while (cin >> comando and comando != "fin") {
    if (comando == "nuevo_jugador" or comando == "nj") {
      string p;
      cin >> p;
      cout << "#" << comando << " " << p << endl;
      if (not ranking.alta_jugador(p)) cout << "error: ya existe un jugador con ese nombre" << endl;
      else cout << ranking.mida() << endl;
    }
    else if (comando == "nuevo_torneo" or comando == "nt") {
      string t;
      int c;
      cin >> t >> c;
      cout << "#" << comando << " " << t << " " << c << endl;
      if (c > num_cat or 0 >= c) cout << "error: la categoria no existe" << endl;
      else if (not tour.alta_torneig(t, c)) cout << "error: ya existe un torneo con ese nombre" << endl;
      else cout << tour.mida() << endl;
    }
    else if (comando == "baja_jugador" or comando == "bj") {
      string p;
      cin >> p;
      cout << "#" << comando << " " << p << endl;
      if (not ranking.baixa_jugador(p)) cout << "error: el jugador no existe" << endl;
      else {
        tour.baixa_jugador(p);
        cout << ranking.mida() << endl;
      }
    }
    else if (comando == "baja_torneo" or comando == "bt") {
      string t;
      cin >> t;
      cout << "#" << comando << " " << t << endl;
      if (not tour.baixa_torneig(t, ranking)) cout << "error: el torneo no existe" << endl;
      else {
        cout << tour.mida() << endl;
        ranking.ordenar_ranking();
      }
    }
    else if (comando == "iniciar_torneo" or comando == "it") {
      string t;
      int n;
      cin >> t >> n;
      cout << "#" << comando << " " << t << endl;
      tour.iniciar_torneig(t, ranking, n);
    }
    else if (comando == "finalizar_torneo" or comando == "ft") {
      string t;
      cin >> t;
      cout << "#" << comando << " " << t << endl;
      tour.finalitzar_torneig(t, ranking, categories);
      ranking.ordenar_ranking();
    }
    else if (comando == "listar_ranking" or comando == "lr") {
      cout << "#" << comando << endl;
      ranking.imprimeix_ranking();
    }
    else if (comando == "listar_jugadores" or comando == "lj") {
      cout << "#" << comando << endl << ranking.mida() << endl;
      ranking.imprimeix_jugadors();
    }
    else if (comando == "consultar_jugador" or comando == "cj") {
      string p;
      cin >> p;
      cout << "#" << comando << " " << p << endl;
      if (not ranking.imprimeix_jugador(p)) cout << "error: el jugador no existe" << endl;
    }
    else if (comando == "listar_torneos" or comando == "lt") {
      cout << "#" << comando << endl << tour.mida() << endl;
      tour.imprimeix_tour(categories);
    }
    else if (comando == "listar_categorias" or comando == "lc") {
      cout << "#" << comando << endl << categories.num_ctgs() << " " << categories.num_nvls() << endl;
      categories.imprimeix_categories();
    }
    else if (comando == "resultados_torneo" or comando == "rt") {
      string t;
      cin >> t;
      cout << "#" << comando << " " << t << endl;
      if (not tour.buscar_torneig(t)) cout << "error: el torneo no existe" << endl;
      else if (not tour.consultar_iniciat(t)) cout << "error: torneo no disputado" << endl;
      else if (not tour.imprimir_resultats(t)) cout << "error: torneo en juego" << endl;
    }
    else if (comando == "mejor_jugador_sets" or comando == "mjs") {
      cout << "#" << comando << endl;
      ranking.imprimeix_millor_jugador_sets();
    }
  }
}
