#include <vector>
using namespace std;

struct parint {int prim, seg;};
 
parint max_min1(const vector<int>& v) {
/* Pre: v.size() > 0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
    int max = v[0];
    int min = v[0];
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        if (v[i] > max) max = v[i];
        if (v[i] < min) min = v[i];
    }
    parint x;
    x.prim = max;
    x.seg = min;
    return x;
}
 
pair<int,int> max_min2(const vector<int>& v) {
/* Pre: v.size() > 0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
    int max = v[0];
    int min = v[0];
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        if (v[i] > max) max = v[i];
        if (v[i] < min) min = v[i];
    }
    pair<int, int> x;
    x.first = max;
    x.second = min;
    return x;
}
 
void max_min3(const vector<int>& v, int& x, int& y) {
/* Pre: v.size() > 0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
    x = v[0];
    y = v[0];
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        if (v[i] > x) x = v[i];
        if (v[i] < y) y = v[i];
    }
}
