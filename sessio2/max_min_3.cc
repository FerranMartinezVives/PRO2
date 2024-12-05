#include "Estudiant.hh"
#include <vector>
using namespace std;

bool comp_max(const Estudiant& a, const Estudiant& b) {
    double max = a.consultar_nota();
    double x = b.consultar_nota();
    if (max > x) return false;
    if (max < x) return true;
    int max_dni = a.consultar_DNI();
    int x_dni = b.consultar_DNI();
    return x_dni < max_dni;
}

bool comp_min(const Estudiant& a, const Estudiant& b) {
    double min = a.consultar_nota();
    double x = b.consultar_nota();
    if (min < x) return false;
    if (min > x) return true;
    int min_dni = a.consultar_DNI();
    int x_dni = b.consultar_DNI();
    return x_dni < min_dni;
}

pair<int, int> max_min_vest(const vector<Estudiant>& v) {
    int max = -1;
    int min = -1;
    int tam = v.size();
    for (int i = 0; i < tam; ++i) {
        if (v[i].te_nota()) {
            if (max == -1) {
                max = i;
                min = i;
            }
            else {
                if (comp_max(v[max], v[i])) max = i;
                else if (comp_min(v[min], v[i])) min = i;
            }
        }
    }
    pair<int, int> max_min_pos;
    max_min_pos.first = max;
    max_min_pos.second = min;
    return max_min_pos;
}
