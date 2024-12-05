#include "vectorIOEstudiant.hh"
using namespace std;

pair<double,double> max_min(const vector<Estudiant>& v) {
    double max = -1;
    double min = -1;
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        if (v[i].te_nota()) {
            double x = v[i].consultar_nota();
            if (max == -1) {
                max = x;
                min = x;
            }
            else {
                if (x > max) max = x;
                if (x < min) min = x;
            }
        }
    }
    pair<double,double> max_and_min;
    max_and_min.first = max;
    max_and_min.second = min;
    return max_and_min;
}

int main() {
    vector<Estudiant> v;
    leer_vector_Estudiant(v);
    pair<double,double> max_and_min = max_min(v);
    cout << max_and_min.first << " " << max_and_min.second << endl;
}
