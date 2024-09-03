#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream archivo("dataset.txt");
    ofstream archivo_salida("salida_sort_std.txt");
    ofstream archivo_salida2("salida_sort_std2.txt");
    int casos, n;
    archivo >> casos;
    for (int i = 0; i < casos; i++) {
        archivo >> n;
        archivo_salida2 << n << " ";
        vector<int> arreglo(n);
        for (int j = 0; j < n; j++) {
            archivo >> arreglo[j];
        }
        auto start = chrono::high_resolution_clock::now();
        sort(arreglo.begin(), arreglo.end());
        auto end = chrono::high_resolution_clock::now();
        auto duracion = chrono::duration_cast<chrono::nanoseconds>(end - start);
        for (int j = 0; j < n; j++) {
            archivo_salida << arreglo[j] << " ";
        }
        archivo_salida << endl;
        archivo_salida << "Tiempo de ejecución: " << duracion.count() << " nanosegundos " << endl;
        archivo_salida2 << duracion.count() << endl;
    }
}