#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matrix;

void read_mat(Matrix& mat) {
    int x = mat.size();
    int y = mat[0].size();
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) cin >> mat[i][j];
    }
}

void product(Matrix& mat_prod, Matrix& mat_1, Matrix& mat_2) {
    int x_1 = mat_1.size();
    int x_2 = mat_2.size();
    int y_2 = mat_2[0].size();
    for (int i = 0; i < x_1; ++i) {
        for (int j = 0; j < y_2; ++j) {
            for (int k = 0; k < x_2; ++k) mat_prod[i][j] += mat_1[i][k] * mat_2[k][j];
        }
    }
}

int main() {
    int x_1, y_1, x_2, y_2;
    cin >> x_1 >> y_1;
    Matrix mat_1(x_1, vector<int>(y_1));
    read_mat(mat_1);
    cin >> x_2 >> y_2;
    Matrix mat_2(x_2, vector<int>(y_2));
    read_mat(mat_2);
    Matrix mat_prod(x_1, vector<int>(y_2));
    product(mat_prod, mat_1, mat_2);
    for (int i = 0; i < x_1; ++i) {
        for (int j = 0; j < y_2; ++j) cout << mat_prod[i][j] << " ";
        cout << endl;
    }
}
