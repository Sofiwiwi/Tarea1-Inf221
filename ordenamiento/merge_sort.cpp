#include<bits/stdc++.h>
using namespace std;


void merge(int arreglo[], int inicio, int mitad, int fin) {
    int n1 = mitad - inicio + 1;
    int n2 = fin - mitad;
    int *arreglo1 = new int[n1];
    int *arreglo2 = new int[n2];
    for (int i = 0; i < n1; i++) {
        arreglo1[i] = arreglo[inicio + i];
    }
    for (int i = 0; i < n2; i++) {
        arreglo2[i] = arreglo[mitad + 1 + i];
    }
    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) { 
        if (arreglo1[i] <= arreglo2[j]) {
            arreglo[k] = arreglo1[i];
            i++;
        } else {
            arreglo[k] = arreglo2[j];
            j++;
        }
        k++;
    }
    while (i < n1) { 
        arreglo[k] = arreglo1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arreglo[k] = arreglo2[j];
        j++;
        k++;
    }
    delete[] arreglo1;
    delete[] arreglo2;
}


void merge_sort(int arreglo[], int inicio, int fin) {
    if (inicio < fin) {
        int mitad = (inicio + fin) / 2;
        merge_sort(arreglo, inicio, mitad); 
        merge_sort(arreglo, mitad + 1, fin); 
        merge(arreglo, inicio, mitad, fin);
    }
}


int main(){
    ifstream archivo("dataset.txt");
    ofstream archivo_salida("salidas/salida_merge_sort.txt");
    ofstream archivo_salida2("salidas para graficar/salida_merge_sort2.txt");
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
        merge_sort(arreglo, 0, n - 1);
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