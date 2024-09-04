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
    ifstream al("datasets/dataset_aleatorio.txt");
    ifstream ord("datasets/dataset_ordenado.txt");
    ifstream inv("datasets/dataset_inverso.txt");

    ofstream sal_al("salidas/merge_sort_salida_al.txt");
    ofstream sal_ord("salidas/merge_sort_salida_ord.txt");
    ofstream sal_inv("salidas/merge_sort_salida_inv.txt");

    ofstream gr_al("salidas para graficar/merge_sort_salida_al.txt");
    ofstream gr_ord("salidas para graficar/merge_sort_salida_ord.txt");
    ofstream gr_inv("salidas para graficar/merge_sort_salida_inv.txt");

    int caso_al, casos, n, m;
    al >> casos;
    for (int i = 0; i < casos; i++) {
        al >> n;
        int arreglo[n];
        for (int j = 0; j < n; j++) {
            al >> arreglo[j];
        }
        auto start = chrono::steady_clock::now();
        merge_sort(arreglo, 0, n - 1);
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
        merge_sort(arreglo, 0, n - 1);
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
        merge_sort(arreglo, 0, n - 1);
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