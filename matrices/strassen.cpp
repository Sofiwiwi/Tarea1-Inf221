#include<bits/stdc++.h>
using namespace std;
typedef long long lld;

using lld = long long;

vector<vector<lld>> suma(const vector<vector<lld>>& x, const vector<vector<lld>>& y){
    int n = x.size();
    vector<vector<lld>> z(n, vector<lld>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            z[i][j] = x[i][j] + y[i][j];
        }
    }
    return z;
}

vector<vector<lld>> resta(const vector<vector<lld>>& x, const vector<vector<lld>>& y){
    int n = x.size();
    vector<vector<lld>> z(n, vector<lld>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            z[i][j] = x[i][j] - y[i][j];
        }
    }
    return z;
}


vector<vector<lld>> strassen(const vector<vector<lld>> &A, const vector<vector<lld>> &B){
    int n = A.size();
    if (n == 1) {
        vector<vector<lld>> C(1, vector<lld>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    int m = n / 2;
    vector<vector<lld>> A11(m, vector<lld>(m));
    vector<vector<lld>> A12(m, vector<lld>(m));
    vector<vector<lld>> A21(m, vector<lld>(m));
    vector<vector<lld>> A22(m, vector<lld>(m));
    vector<vector<lld>> B11(m, vector<lld>(m));
    vector<vector<lld>> B12(m, vector<lld>(m));
    vector<vector<lld>> B21(m, vector<lld>(m));
    vector<vector<lld>> B22(m, vector<lld>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + m];
            A21[i][j] = A[i + m][j];
            A22[i][j] = A[i + m][j + m];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + m];
            B21[i][j] = B[i + m][j];
            B22[i][j] = B[i + m][j + m];
        }
    }

    vector<vector<lld>> P1 = strassen(suma(A11, A22), suma(B11, B22));
    vector<vector<lld>> P2 = strassen(suma(A21, A22), B11);
    vector<vector<lld>> P3 = strassen(A11, resta(B12, B22));
    vector<vector<lld>> P4 = strassen(A22, resta(B21, B11));
    vector<vector<lld>> P5 = strassen(suma(A11, A12), B22);
    vector<vector<lld>> P6 = strassen(resta(A21, A11), suma(B11, B12));
    vector<vector<lld>> P7 = strassen(resta(A12, A22), suma(B21, B22));

    vector<vector<lld>> C11 = suma(resta(suma(P1, P4), P5), P7);
    vector<vector<lld>> C12 = suma(P3, P5);
    vector<vector<lld>> C21 = suma(P2, P4);
    vector<vector<lld>> C22 = suma(resta(suma(P1, P3), P2), P6);

    vector<vector<lld>> C(n, vector<lld>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = C11[i][j];
            C[i][j + m] = C12[i][j];
            C[i + m][j] = C21[i][j];
            C[i + m][j + m] = C22[i][j];
        }
    }
    return C;
}


int main(){
    ifstream nn("datasets/dataset_nxn.txt");
    ofstream sal_nn("salidas/strassen_salida_nn.txt");
    ofstream gr_nn("salidas para graficar/strassen_salida_nn.txt");
    int casos, n;
    nn >> casos;
    for (int i = 0; i < casos; i++) {
        nn >> n >> n;
        if (log2(n) != (int)log2(n)) {
            sal_nn << "No se puede realizar la multiplicacion de matrices" << endl;
            gr_nn << 0 << " " 
            << 0 << endl;
            int basura;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    nn >> basura;
                }
            }
            continue;
        }
        vector<vector<lld>> matriz_A(n, vector<lld>(n));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                nn >> matriz_A[j][k];
            }
        }
        nn >> n >> n;
        vector<vector<lld>> matriz_B(n, vector<lld>(n));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                nn >> matriz_B[j][k];
            }
        }
        vector<vector<lld>> matriz_C(n, vector<lld>(n));
        auto start = chrono::steady_clock::now();
        matriz_C = strassen(matriz_A, matriz_B);
        auto end = chrono::steady_clock::now();
        auto duracion = chrono::duration_cast<chrono::nanoseconds>(end - start);

        sal_nn << duracion.count() << endl;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                sal_nn << matriz_C[j][k] << " ";
            }
            sal_nn << endl;
        }
        gr_nn << n << " " << duracion.count() << endl;
    }
    nn.close();
    sal_nn.close();
    gr_nn.close();
    return 0;
}