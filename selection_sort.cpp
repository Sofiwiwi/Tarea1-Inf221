#include <iostream>
using namespace std;


void print_array(int arreglo[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
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
    int n;
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;
    int arreglo[n];
    cout << "Ingrese los elementos: ";
    for (int i = 0; i < n; i++) {
        cin >> arreglo[i];
    }
    selection_sort(arreglo, n);
    print_array(arreglo, n);
    return 0;
}

