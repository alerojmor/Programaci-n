/*Ejercicio 2: Insertion Sort Básico
Crear un programa que:
Permita ingresar 6 notas de estudiantes (enteros del 1 al 10)
Ordene las notas de menor a mayor usando Insertion Sort
Muestre las notas antes y después del ordenamiento*/

#include <iostream>
using namespace std;

void ingresarNotas(int notas[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "Ingrese la nota del estudiante " << (i + 1) << " (entre 1 y 10): ";
        cin >> notas[i];
        while (notas[i] < 1 || notas[i] > 10) {
            cout << "Nota inválida. Ingrese nuevamente: ";
            cin >> notas[i];
        }
    }
}

void insertionSort(int notas[], int cantidad) {
    for (int i = 1; i < cantidad; i++) {
        int clave = notas[i];
        int j = i - 1;

        // Mover los elementos de notas[0..i-1] que son mayores que clave
        while (j >= 0 && notas[j] > clave) {
            notas[j + 1] = notas[j];
            j--;
        }
        notas[j + 1] = clave;
    }
}

void mostrarNotas(int notas[], int cantidad) {
    cout << "Notas: ";
    for (int i = 0; i < cantidad; i++) {
        cout << notas[i] << " ";
    }
    cout << endl;
}

int main() {
    const int CANTIDAD_NOTAS = 6;
    int notas[CANTIDAD_NOTAS];

    // Ingreso de notas
    ingresarNotas(notas, CANTIDAD_NOTAS);
    // Mostrar notas antes del ordenamiento
    cout << "Notas antes del ordenamiento:" << endl;
    mostrarNotas(notas, CANTIDAD_NOTAS);
    // Ordenar notas
    insertionSort(notas, CANTIDAD_NOTAS);
    // Mostrar notas después del ordenamiento
    cout << "Notas después del ordenamiento:" << endl;
    mostrarNotas(notas, CANTIDAD_NOTAS);

    return 0;
}   
