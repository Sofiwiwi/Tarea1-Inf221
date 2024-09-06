#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> cubico_trad(vector<vector<int>> &matriz_A, vector<vector<int>> &matriz_B){
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


int main(){
    ifstream nmp("datasets/dataset_mnp.txt");
    ifstream nn("datasets/dataset_nxn.txt");

    ofstream sal_mnp("salidas/cubico_trad_salida_mnp.txt");
    ofstream sal_nn("salidas/cubico_trad_salida_nn.txt");

    ofstream gr_mnp("salidas para graficar/cubico_trad_salida_mnp.txt");
    ofstream gr_nn("salidas para graficar/cubico_trad_salida_nn.txt");
    int casos, n, m, p;
    nmp >> casos;
    for (int i = 0; i < casos; i++) {
        nmp >> n >> m;
        vector<vector<int>> matriz_A(n, vector<int>(m));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                nmp >> matriz_A[j][k];
            }
        }
        nmp >> m >> p;
        vector<vector<int>> matriz_B(m, vector<int>(p));
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                nmp >> matriz_B[j][k];
            }
        }
        vector<vector<int>> matriz_C;
        auto start = chrono::steady_clock::now();
        matriz_C = cubico_trad(matriz_A, matriz_B);
        auto end = chrono::steady_clock::now();
        auto duracion = chrono::duration_cast<chrono::nanoseconds>(end - start);
        sal_mnp << duracion.count() << endl;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < p; k++) {
                sal_mnp << matriz_C[j][k] << " ";
            }
            sal_mnp << endl;
        }
        int vol = n * m * p;
        gr_mnp << vol << " " << duracion.count() << endl;  
    }
    nn >> casos;
    for (int i = 0; i < casos; i++) {
        nn >> n >> n;
        vector<vector<int>> matriz_A(n, vector<int>(n));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                nn >> matriz_A[j][k];
            }
        }
        nn >> n >> n;
        vector<vector<int>> matriz_B(n, vector<int>(n));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                nn >> matriz_B[j][k];
            }
        }
        vector<vector<int>> matriz_C;
        auto start = chrono::steady_clock::now();
        matriz_C = cubico_trad(matriz_A, matriz_B);
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
    nmp.close();
    nn.close();
    sal_mnp.close();
    sal_nn.close();
    gr_mnp.close();
    gr_nn.close();
    return 0;
}