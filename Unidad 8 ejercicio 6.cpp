/*Ejercicio 6: Inventario de Productos
Crear un programa que maneje un inventario de 12 productos (stock):
Usar Burbujeo Mejorado para ordenar por cantidad de stock
Usar Búsqueda Secuencial para buscar productos con stock específico
Identificar productos con stock bajo (menos de 10 unidades)*/

#include <iostream>
using namespace std;

struct Producto {
    string nombre;
    int stock;
};

void burbujeoMejorado(Producto productos[], int n) 
{
    int i = 0;
    bool ordenado = false;
    while(i<n && !ordenado) {
        ordenado = true;
        for (int j = 0; j < n - i - 1; j++) {
            if (productos[j].stock > productos[j + 1].stock) {
                Producto aux = productos[j];
                productos[j] = productos[j + 1];
                productos[j + 1] = aux;
                ordenado = false;
            }
        }
        i++;
    }
}

int busquedaSecuencial(Producto productos[], int n, int stockBuscado) {
    for (int i = 0; i < n; i++) {
        if (productos[i].stock == stockBuscado) {
            return i;
        }
    }
    return -1;
}

void identificarStockBajo(Producto productos[], int n) {
    cout << "Productos con stock bajo (menos de 10 unidades):" << endl;
    for (int i = 0; i < n; i++) {
        if (productos[i].stock < 10) {
            cout << "- " << productos[i].nombre << " (Stock: " << productos[i].stock << ")" << endl;
        }
    }
}

int main() {
    Producto inventario[12] = {
        {"Producto 1", 15},
        {"Producto 2", 8},
        {"Producto 3", 12},
        {"Producto 4", 5},
        {"Producto 5", 20},
        {"Producto 6", 3},
        {"Producto 7", 10},
        {"Producto 8", 7},
        {"Producto 9", 18},
        {"Producto 10", 2},
        {"Producto 11", 25},
        {"Producto 12", 1}
    };

    burbujeoMejorado(inventario, 12);

    int stockBuscado;
    cout << "Ingrese el stock a buscar: ";
    cin >> stockBuscado;

    int resultado = busquedaSecuencial(inventario, 12, stockBuscado);
    if (resultado != -1) {
        cout << "Producto encontrado: " << inventario[resultado].nombre << endl;
    } else {
        cout << "Producto no encontrado." << endl;
    }

    identificarStockBajo(inventario, 12);

    return 0;
}