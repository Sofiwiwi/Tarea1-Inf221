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

void quick_sort_rec(int arreglo[], int inicio, int fin) {
    if (inicio < fin) {
        int pivote = partition(arreglo, inicio, fin);
        quick_sort_rec(arreglo, inicio, pivote - 1);
        quick_sort_rec(arreglo, pivote + 1, fin);
    }
}

void maxheapify(int arreglo[], int n, int i) {
    int max = i;
    int izq = 2 * i + 1;
    int der = 2 * i + 2;
    if (izq < n && arreglo[izq] > arreglo[max]) {
        max = izq;
    }
    if (der < n && arreglo[der] > arreglo[max]) {
        max = der;
    }
    if (max != i) {
        swap(arreglo[i], arreglo[max]);
        maxheapify(arreglo, n, max);
    }
}

void heap_sort(int arreglo[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxheapify(arreglo, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arreglo[0], arreglo[i]);
        maxheapify(arreglo, i, 0);
    }
}


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

void introsort(int arreglo[], int n) {
    int tamano_part = partition(arreglo, 0, n - 1);
    if (tamano_part < 16) {
        insertion_sort(arreglo, n);
    } else if (n > (2 * log(n))) {
        heap_sort(arreglo, n);
    } else {
        quick_sort_rec(arreglo, 0, n - 1);
    }
}


int main(){
    ifstream al("datasets/dataset_aleatorio.txt");
    ifstream ord("datasets/dataset_ordenado.txt");
    ifstream inv("datasets/dataset_inverso.txt");

    ofstream sal_al("salidas/introsort_salida_al.txt");
    ofstream sal_ord("salidas/introsort_salida_ord.txt");
    ofstream sal_inv("salidas/introsort_salida_inv.txt");

    ofstream gr_al("salidas para graficar/introsort_salida_al.txt");
    ofstream gr_ord("salidas para graficar/introsort_salida_ord.txt");
    ofstream gr_inv("salidas para graficar/introsort_salida_inv.txt");

    int caso_al, casos, n, m;
    al >> casos;
    for (int i = 0; i < casos; i++) {
        al >> n;
        int arreglo[n];
        for (int j = 0; j < n; j++) {
            al >> arreglo[j];
        }
        auto start = chrono::steady_clock::now();
        introsort(arreglo, n);
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
        introsort(arreglo, n);
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
        introsort(arreglo, n);
        auto end = chrono::steady_clock::now();
        auto duracion = chrono::duration_cast<chrono::nanoseconds>(end - start);
        sal_inv << duracion.count() << endl;
        for (int j = 0; j < n; j++) {
            sal_inv << arreglo[j] << " ";
        }
        sal_inv << endl;
        gr_inv << n << " " << duracion.count() << endl;
    }
}