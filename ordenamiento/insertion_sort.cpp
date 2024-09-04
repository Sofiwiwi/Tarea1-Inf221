#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arreglo[], int n) {
    for (int i = 1; i < n; i++) {
        int llave = arreglo[i];
        int j = i - 1;
        while (j >= 0 && arreglo[j] > llave) {
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        arreglo[j + 1] = llave;
    }
}

int main(){
    ifstream archivo("dataset.txt");
    ofstream archivo_salida("salidas/salida_insertion_sort.txt");
    ofstream archivo_salida2("salidas para graficar/salida_insertion_sort2.txt");
    int casos, n;
    archivo >> casos;
    for (int i = 0; i < casos; i++) {
        archivo >> n;
        archivo_salida2 << n << " ";
        int *arreglo = new int[n];
        for (int j = 0; j < n; j++) {
            archivo >> arreglo[j];
        }
        auto start = chrono::high_resolution_clock::now();
        insertion_sort(arreglo, n);
        auto end = chrono::high_resolution_clock::now();
        auto duracion = chrono::duration_cast<chrono::nanoseconds>(end - start);
        for (int j = 0; j < n; j++) {
            archivo_salida << arreglo[j] << " ";
        }
        archivo_salida << endl;
        archivo_salida << "Tiempo de ejecución: " << duracion.count() << " nanosegundos " << endl;
        archivo_salida2 << duracion.count() << endl;
        delete[] arreglo;
    }
}