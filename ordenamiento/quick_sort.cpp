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
    ifstream al("datasets/dataset_aleatorio.txt");
    ifstream ord("datasets/dataset_ordenado.txt");
    ifstream inv("datasets/dataset_inverso.txt");

    ofstream sal_al("salidas/quick_sort_salida_al.txt");
    ofstream sal_ord("salidas/quick_sort_salida_ord.txt");
    ofstream sal_inv("salidas/quick_sort_salida_inv.txt");

    ofstream gr_al("salidas para graficar/quick_sort_salida_al.txt");
    ofstream gr_ord("salidas para graficar/quick_sort_salida_ord.txt");
    ofstream gr_inv("salidas para graficar/quick_sort_salida_inv.txt");

    int caso_al, casos, n, m;
    al >> casos;
    for (int i = 0; i < casos; i++) {
        al >> n;
        int arreglo[n];
        for (int j = 0; j < n; j++) {
            al >> arreglo[j];
        }
        auto start = chrono::steady_clock::now();
        quick_sort(arreglo, 0, n - 1);
        auto end = chrono::steady_clock::now();
        auto duracion = chrono::duration_cast<chrono::nanoseconds>(end - start);
        sal_al << duracion.count() << endl;
        for (int j = 0; j < n; j++) {
            sal_al << arreglo[j] << " ";
        }
        sal_al << endl;
        gr_al << n << " " << duracion.count() << endl;
    }
    ord >> casos;
    for (int i = 0; i < casos; i++) {
        ord >> n;
        int arreglo[n];
        for (int j = 0; j < n; j++) {
            ord >> arreglo[j];
        }
        auto start = chrono::steady_clock::now();
        quick_sort(arreglo, 0, n - 1);
        auto end = chrono::steady_clock::now();
        auto duracion = chrono::duration_cast<chrono::nanoseconds>(end - start);
        sal_ord << duracion.count() << endl;
        for (int j = 0; j < n; j++) {
            sal_ord << arreglo[j] << " ";
        }
        sal_ord << endl;
        gr_ord << n << " " << duracion.count() << endl;
    }
    inv >> casos;
    for (int i = 0; i < casos; i++) {
        inv >> n;
        int arreglo[n];
        for (int j = 0; j < n; j++) {
            inv >> arreglo[j];
        }
        auto start = chrono::steady_clock::now();
        quick_sort(arreglo, 0, n - 1);
        auto end = chrono::steady_clock::now();
        auto duracion = chrono::duration_cast<chrono::nanoseconds>(end - start);
        sal_inv << duracion.count() << endl;
        for (int j = 0; j < n; j++) {
            sal_inv << arreglo[j] << " ";
        }
        sal_inv << endl;
        gr_inv << n << " " << duracion.count() << endl;
    }
    al.close();
    ord.close();
    inv.close();
    sal_al.close();
    sal_ord.close();
    sal_inv.close();
    gr_al.close();
    gr_ord.close();
    gr_inv.close();
    return 0;
}