#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> multiplicar(vector<vector<int>> &matriz_A, vector<vector<int>> &matriz_B){
    int n = matriz_A.size();
    int m = matriz_A[0].size();
    int p = matriz_B[0].size();
    vector<vector<int>> matriz_C(n, vector<int>(p));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            matriz_C[i][j] = 0;
            for (int k = 0; k < m; k++) {
                matriz_C[i][j] += matriz_A[i][k] * matriz_B[k][j];
            }
        }
    }
    return matriz_C;
}


vector<vector<int>> trasponer(vector<vector<int>> &matriz){
    int n = matriz.size();
    int m = matriz[0].size();
    vector<vector<int>> matriz_T(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matriz_T[j][i] = matriz[i][j];
        }
    }
    return matriz_T;
}

int main(){
    ifstream archivo("dataset.txt");
    ofstream archivo_salida("salidas/salida_cubico_it.txt");
    ofstream archivo_salida2("salidas para graficar/salida_cubico_it2.txt");
    int casos, n, m, p;
    archivo >> casos;
    for (int i = 0; i < casos; i++) {
        archivo >> n >> m;
        vector<vector<int>> matriz_A(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                archivo >> matriz_A[i][j];
            }
        }
        archivo >> m >> p;
        vector<vector<int>> matriz_B(m, vector<int>(p));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < p; j++) {
                archivo >> matriz_B[i][j];
            }
        }
        vector<vector<int>> matriz_B_T = trasponer(matriz_B);
        auto start = chrono::high_resolution_clock::now();
        vector<vector<int>> matriz_C = multiplicar(matriz_A, matriz_B_T);
        auto end = chrono::high_resolution_clock::now();
        auto duracion = chrono::duration_cast<chrono::nanoseconds>(end - start);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                archivo_salida << matriz_C[i][j] << " ";
            }
            archivo_salida << "\n";
        }
        archivo_salida << duracion.count() << "\n";
        archivo_salida2 << n << "x" << m << " " << m << "x" << p << " " << duracion.count() << "\n";
    }
}