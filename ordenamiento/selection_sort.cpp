#include <iostream> 
#include <fstream>
#include <chrono>
using namespace std;

void print_array(int arreglo[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

void selection_sort(int arreglo[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int elemento_menor = i;
        for (int j = i + 1; j < n; j++) {
            if (arreglo[j] < arreglo[elemento_menor]) {
                elemento_menor = j;
            }
        }
        swap(arreglo[i], arreglo[elemento_menor]);
    }
}

int main() {
    ifstream archivo("dataset.txt");
    ofstream archivo_salida("salida_selection_sort.txt");
    if (!archivo) {
        cout << "No se pudo abrir el archivo" << endl;
        return 1;
    }
    int casos, n;
    archivo >> casos;
    for (int i = 0; i < casos; i++) {
        archivo >> n;
        int *arreglo = new int[n];
        for (int j = 0; j < n; j++) {
            archivo >> arreglo[j];
        }
        auto start = chrono::high_resolution_clock::now();
        selection_sort(arreglo, n);
        auto end = chrono::high_resolution_clock::now();
        auto duracion = chrono::duration_cast<chrono::nanoseconds>(end - start);
        for (int j = 0; j < n; j++) {
            archivo_salida << arreglo[j] << " ";
        }
        archivo_salida << endl;
        archivo_salida << "Tiempo de ejecución: " << duracion.count() << " nanosegundos " << endl;
        delete[] arreglo;
    }
    return 0;
}