#include "Estudiant.hh"
#include <vector>
using namespace std;

pair<int, int> max_min_vest(const vector<Estudiant>& v) {
    int max_pos = -1;
    int min_pos = -1;
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        if (v[i].te_nota()) {
            if (max_pos == -1) {
                max_pos = i;
                min_pos = i;
            }
            else {
                double x = v[i].consultar_nota();
                double max = v[max_pos].consultar_nota();
                double min = v[min_pos].consultar_nota();
                if (x > max) max_pos = i;
                if (x < min) min_pos = i;
            }
        }
    }
    pair<int, int> max_min_pos;
    max_min_pos.first = max_pos;
    max_min_pos.second = min_pos;
    return max_min_pos;
}
