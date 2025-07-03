/*Ejercicio 3: Burbujeo Simple
Crear un programa que:
Permita ingresar 7 temperaturas diarias (números decimales)
Ordene las temperaturas de menor a mayor usando Burbujeo
Muestre el resultado final*/

#include <iostream>
using namespace std;

void ingresarTemperaturas(float temperaturas[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "Ingrese la temperatura del día " << (i + 1) << ": ";
        cin >> temperaturas[i];
    }
}

void burbujeo(float temperaturas[], int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (temperaturas[j] > temperaturas[j + 1]) {
                // Intercambiar
                float temp = temperaturas[j];
                temperaturas[j] = temperaturas[j + 1];
                temperaturas[j + 1] = temp;
            }
        }
    }
}

void mostrarTemperaturas(float temperaturas[], int cantidad) {
    cout << "Temperaturas ordenadas: ";
    for (int i = 0; i < cantidad; i++) {
        cout << temperaturas[i] << " ";
    }
    cout << endl;
}

int main() {
    const int CANTIDAD_TEMPERATURAS = 7;
    float temperaturas[CANTIDAD_TEMPERATURAS];

    // Ingreso de temperaturas
    ingresarTemperaturas(temperaturas, CANTIDAD_TEMPERATURAS);
    // Ordenar temperaturas
    burbujeo(temperaturas, CANTIDAD_TEMPERATURAS);
    // Mostrar temperaturas ordenadas
    mostrarTemperaturas(temperaturas, CANTIDAD_TEMPERATURAS);

    return 0;
}
