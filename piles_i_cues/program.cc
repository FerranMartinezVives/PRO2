#include "CuaIOParInt.hh"
using namespace std;

int main() {
    queue<ParInt> og_q;
    llegirCuaParInt(og_q);
    queue<ParInt> q_1, q_2;
    int time_1 = 0;
    int time_2 = 0;
    while (not og_q.empty()) {
        if (time_1 > time_2) {
            q_2.push(og_q.front());
            time_2 += og_q.front().segon();
        }
        else {
            q_1.push(og_q.front());
            time_1 += og_q.front().segon();
        }
        og_q.pop();
    }
    escriureCuaParInt(q_1);
    cout << endl;
    escriureCuaParInt(q_2);
}
