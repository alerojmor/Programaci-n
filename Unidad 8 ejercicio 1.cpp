/*Ejercicio 1: Búsqueda Secuencial
Crear un programa que:
Permita al usuario ingresar 8 números enteros en un vector
Permita buscar un número específico
Informe si el número está presente y en qué posición
Si no está, mostrar "Número no encontrado"*/

#include <iostream>
using namespace std;  

 void ingresarNumeros(int numeros[], int cantidad)
    {
        for (int i = 0; i < cantidad; i++) {
            cout << "Ingrese el numero " << (i + 1) << ": ";
            cin >> numeros[i];
        }
    }

void buscarNumero(int numeros[], int cantidad, int &numeroBuscado, bool &encontrado, int &posicion)
{
    cout << "Ingrese el numero a buscar: ";
    cin >> numeroBuscado;

    for (int i = 0; i < cantidad; i++) {
        if (numeros[i] == numeroBuscado) {
            encontrado = true;
            posicion = i;
            break;
        }
    }
}    

void informarNumero(bool encontrado, int posicion, int numeroBuscado)
{
    if (encontrado) {
        cout << "El numero " << numeroBuscado << " se encuentra en la posicion: " << posicion << endl;
    } else {
        cout << "Numero no encontrado" << endl;
    }
}

int main() 
{
    int numeros[8];
    int numeroBuscado;
    bool encontrado = false;
    int posicion = -1;

    // Ingreso de números al vector
    ingresarNumeros(numeros, 8);
    // Búsqueda del número
    buscarNumero(numeros, 8, numeroBuscado, encontrado, posicion);
    // Informar resultado de la búsqueda
    informarNumero(encontrado, posicion, numeroBuscado);
    
    return 0;
}

