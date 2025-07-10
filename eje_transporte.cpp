#include <iostream>

using namespace std;

struct Viaje
{
    string patente;
    int hora_inicio;
    int hora_fin;
    long kilometros;
    double precio;
};

struct Vehiculo
{
    string patente;
    string modelo;
    double consumo_por_kilómetro;
};

void ordenar_vehiculo(Vehiculo cars[], int nCars)
{
    for (int i = 0; i < nCars - 1; i++)
    {
        for (int j = i + 1; j < nCars; j++)
        {
            if (cars[i].modelo > cars[j].modelo)
            {
                Vehiculo aux = cars[j];
                cars[j] = cars[i];
                cars[i] = aux;
            }
        }
    }
}
void ordenar_patente(Vehiculo cars[], int nCars)
{
    for (int i = 0; i < nCars - 1; i++)
    {
        for (int j = i + 1; j < nCars; j++)
        {
            if (cars[i].patente > cars[j].patente)
            {
                Vehiculo aux = cars[j];
                cars[j] = cars[i];
                cars[i] = aux;
            }
        }
    }
}

int busqueda_patente(Vehiculo cars[], int nCars, string valor)
{
    int inicio = 0;
    int fin = nCars - 1;
    int posicion = -1;

    while (inicio <= fin)
    {
        int medio = inicio + (fin - inicio) / 2;

        if (cars[medio].patente == valor)
        {
            posicion = medio;
        }

        if (cars[medio].patente > valor)
        {
            fin = medio - 1;
        }
        else
        {
            inicio = medio + 1;
        }
    }

    return posicion;
}

double calcular_costo_combustible(Viaje viajes[], int nViajes, Vehiculo cars[],int nCars)
{
     double acumulador = 0;

    for (int i = 0; i < nCars; i++)
    {

        acumulador += viajes[i].kilometros * cars[i].consumo_por_kilómetro;
    }

    return acumulador;
}

void rendimiento(Vehiculo cars[], int nCars, Viaje viajes[], int nViajes){
    double patente_max = 0, patente_min = 0;
    int indice_max = 0, indice_min = 0;
    for(int i = 0; i < nViajes; i++ ){
    
        patente_min = (viajes[i].kilometros * cars[i].consumo_por_kilómetro)/viajes[i].precio;
        indice_min = i;
        if(patente_min > patente_max){
            patente_max = patente_min;
            indice_max = i;
        } else {
            indice_min = i;
        }

    }
    cout << "la patente con menor rendimiento es: " << cars[indice_min].patente << " la patente con mayor rendimiento es: " << cars[indice_max].patente << endl; 
}



main()
{
    Viaje listaViajes[3] = {
        {"AAA111", 1600, 1700, 600, 15},
        {"BBB222", 1700, 1800, 700, 16},
        {"CCC333", 1800, 1900, 800, 17.05}};

    Vehiculo vec_vehiculo[3] = {
        {"BBB222", "Renault-Kangoo", 1.2},
        {"AAA111", "Ford-Cargo1-933", 1.5},
        {"CCC333", "Chevrolet-Combo", 1.1}};

    ordenar_patente(vec_vehiculo, 3);

    for (int i = 0; i < 3; i++)
    {
        cout << vec_vehiculo[i].patente << endl;
    }

    int resultado = busqueda_patente(vec_vehiculo, 3, "AAA111");

    cout << "La patente: " << vec_vehiculo[resultado].patente << " esta en la posicion " << resultado << endl;

    double costo = calcular_costo_combustible(listaViajes, 3, vec_vehiculo, 3);

    cout << "el costo total del combustible utilizado por todos los camiones en el día es: " << costo << endl;

    rendimiento(vec_vehiculo,3,listaViajes,3);

    return 0;
}

// Para escribir el código, se asume que los datos ya están cargados en vectores estáticos y que cada vector tiene una variable asociada que indica la cantidad de elementos cargados.
// Se asume que cada vehículo realiza al menos un viaje en el día.

// 1) Escribir una función que ordene el vector de vehículos por modelo (ordenamiento burbuja).
// 2) Escribir una función que busque en el vector de vehículos por patente y devuelva la posición en el vector (búsqueda binaria).
// 3) Escribir una función que calcule el costo total del combustible utilizado por todos los camiones en el día.
// 4) Escribir una función que indique la patente del vehículo con mejor y peor rendimiento, de acuerdo al consumo total de combustible en relación con el total de los importes cobrados por los viajes.