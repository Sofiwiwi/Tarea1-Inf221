#include<bits/stdc++.h>
using namespace std;


int partition(int arreglo[], int inicio, int fin) {
    int pivote = arreglo[fin]; //
    int i = inicio - 1;
    for (int j = inicio; j < fin; j++) {
        if (arreglo[j] < pivote) {
            i++;
            swap(arreglo[i], arreglo[j]);
        }
    }
    swap(arreglo[i + 1], arreglo[fin]);
    return i + 1;
}

void quick_sort(int arreglo[], int inicio, int fin) {
    if (inicio < fin) {
        int pivote = partition(arreglo, inicio, fin);
        quick_sort(arreglo, inicio, pivote - 1);
        quick_sort(arreglo, pivote + 1, fin);
    }
}

int main(){
    ifstream archivo("dataset.txt");
    ofstream archivo_salida("salida_quick_sort.txt");
    ofstream archivo_salida2("salida_quick_sort2.txt");
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
        quick_sort(arreglo, 0, n - 1);
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