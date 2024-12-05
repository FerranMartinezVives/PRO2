#include<iostream>
#include"Conjunt_Categories.hh"
#include"Conjunt_Tornejos.hh"
#include"Ranking.hh"
using namespace std;

int main() {
    int num_cat, max_niv;
    cin >> num_cat >> max_niv;
    Conj_Cat(num_cat, max_niv) categories;
    categories.llegir_punts();
    
    int num_torn;
    cin >> num_torn;
    Conj_Torn(num_torn) tornejos;
    tornejos.llegir_tornejos();
    
    int num_jug;
    cin >> num_jug;
    Ranking(num_jug) ranking;
    
    string comando;
    cin >> comando;
    while (comando != "fin") {
        if (comando == "nuevo_jugador" or comando == "nj") {
            
        }
        else if (comando == "nuevo_torneo" or comando == "nt") {
            
        }
        else if (comando == "baja_jugador" or comando == "bj") {
            
        }
        else if (comando == "baja_torneo" or comando == "bt") {
            
        }
        else if (comando == "iniciar_torneo" or comando == "it") {
            
        }
        else if (comando == "finalizar_torneo" or comando == "ft") {
            
        }
        else if (comando == "listar_ranking" or comando == "lr") {
            
        }
        else if (comando == "listar_jugadores" or comando == "lj") {
            
        }
        else if (comando == "consultar_jugador" or comando == "cj") {
            
        }
        else if (comando == "listar_torneos" or comando == "lt") {
            
        }
        else if (comando == "listar_categorias" or comando == "lc") {
            
        }
    }
}
