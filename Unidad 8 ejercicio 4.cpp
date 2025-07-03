/*Ejercicio 4: Sistema de Calificaciones
Crear un programa que maneje un vector de 10 calificaciones:
Usar Insertion Sort para ordenar las calificaciones
Usar Búsqueda Binaria para verificar si una calificación específica existe
Mostrar la calificación más alta y más baja*/

#include <iostream>
using namespace std;
const int TAMAÑO = 10;

void ingresarCalificaciones(int calificaciones[], int cantidad)
{
    cout << "Ingrese " << cantidad << " calificaciones: " << endl;
    for (int i = 0; i < cantidad; i++)
    {
        cin >> calificaciones[i];
    }
}

void insertionSort(int calificaciones[], int cantidad)
{
    for (int i = 1; i < cantidad; i++)
    {
        int clave = calificaciones[i];
        int j = i - 1;
        while (j >= 0 && calificaciones[j] > clave)
        {
            calificaciones[j + 1] = calificaciones[j];
            j--;
        }
        calificaciones[j + 1] = clave;
    }
}

void mostrarCalificaciones(int calificaciones[], int cantidad)
{
    cout << "Calificaciones ordenadas: ";
    for (int i = 0; i < cantidad; i++)
    {
        cout << calificaciones[i] << " ";
    }
    cout << endl;
}

int busquedaBinaria(int calificaciones[], int cantidad, int valor)
{
    int inicio = 0;
    int fin = cantidad - 1;
    while (fin >= inicio)
    {
        int mitad = inicio + (fin - inicio) / 2;
        if (calificaciones[mitad] == valor)
        {
            return mitad;
        }
        if (calificaciones[mitad] > valor)
        {
            fin = mitad - 1;
        }
        else
        {
            inicio = mitad + 1;
        }
    }
    return -1;
}

int main()
{
    int calificaciones[TAMAÑO];
    ingresarCalificaciones(calificaciones, TAMAÑO);
    insertionSort(calificaciones, TAMAÑO);
    mostrarCalificaciones(calificaciones, TAMAÑO);

    int valor;
    cout << "Ingrese una calificación a buscar: ";
    cin >> valor;
    
    int resultado = busquedaBinaria(calificaciones, TAMAÑO, valor);
    if (resultado != -1)
    {
        cout << "La calificación " << valor << " si está en el listado"<< endl;
    }
    else
    {
        cout << "La calificación " << valor << " no está en el listado." << endl;
    }

    cout << "Calificación más alta: " << calificaciones[TAMAÑO - 1] << endl;
    cout << "Calificación más baja: " << calificaciones[0] << endl;

    return 0;
}