/*Consumo de Combustible en Flota de Transporte de Pasajeros

Una empresa de transporte urbano necesita desarrollar un sistema para evaluar el rendimiento de combustible de su flota, con el objetivo de optimizar costos y detectar conductores o vehículos con baja eficiencia.

La empresa dispone de información de sus vehículos y viajes realizados.

Datos
Vehículos (ordenado por ID de vehículo):

De cada vehículo se conoce:

Id del vehículo (entero)

Tipo de vehículo (1: Mini, 2: Mediano, 3: Grande)

Patente (string)

Consumo por kilómetro (litros/km)

Zona asignada (1: Centro, 2: Norte, 3: Sur)

Viajes (ordenado por ID de vehículo):

De cada viaje se conoce:

Id del vehículo (entero)

Fecha (formato DDMMAAAA)

Hora de inicio (formato 24hs)

Origen (string)

Destino (string)

Distancia recorrida (float)

Litros reales consumidos (float)

Objetivos
1. Definir las estructuras necesarias para representar vehículos y viajes.

2. Desarrollar la función buscarVehiculo que, dado un ID de vehículo, devuelva su posición en el vector de vehículos.

3. Implementar una función generarRendimientos que genere un nuevo vector con el siguiente resumen por vehículo:

Id del vehículo

Tipo de vehículo

Patente

Total de kilómetros recorridos

Total de litros consumidos

Rendimiento real = Km recorridos / Litros consumidos

Rendimiento esperado = 1 / consumo por km

Zona

4. Ordenar por zona de forma ascendente el vector de resumen obtenido en el punto anterior usando una función ordenarPorZona.

5. Generar un reporte por zona, utilizando el vector ordenado:

Nombre de la zona

Total de kilómetros recorridos en la zona

Promedio del rendimiento real en la zona

Diferencia promedio entre rendimiento real y esperado

Consideraciones
Los vectores están previamente cargados.

Todos los vehículos realizaron al menos un viaje.

No hay viajes con 0 km o 0 litros consumidos.

Los tipos de vehículo deben representarse como un enum o const.

Restricciones
Para el punto 4 se debe usar el vector generado en el punto 3.

Para el punto 5 se debe usar el vector ordenado por zona del punto 4.

Deben aplicarse estructuras de datos estáticas (vectores fijos) con un tamaño máximo de 100 elementos.*/


#include <iostream>
using namespace std;

const int MAX_VEHICULOS = 100;
const int MAX_VIAJES = 100;
const int MAX_RENDIMIENTOS = 100;

enum zona{
    centro = 1,
    norte = 2,
    sur = 3
};

enum tipoVehiculo {
    mini = 1,
    mediano = 2,
    grande = 3
};

//1. Definir las estructuras de datos necesarias

struct Vehiculo {
    int id;
    int tipoVehiculo; // 1: Mini, 2: Mediano, 3: Grande
    string patente;
    float consumo;
    int zona;
};

struct Viaje {
    int id;
    long fecha; // formato DDMMAAAA
    int hora; // formato 24hs
    string origen;
    string destino;
    float distancia;
    float litros;
};

//Estructura del punto 3, para almacenar el rendimiento de cada vehículo

struct Rendimiento {
    int id;
    int tipoVehiculo;
    string patente;
    float totalKm;
    float rendReal;
    float rendEsperado;
    int zona;
};

// 2. Función para buscar un vehículo por ID

int buscarVehiculo(Vehiculo vehiculos[], int nVehiculos, int idBuscado)
{
    int inicio = 0;
    int fin = nVehiculos - 1;

    while (fin >= inicio)
    {
        int mitad = inicio + (fin - inicio) / 2;
        if (vehiculos[mitad].id == idBuscado) 
        {
            return mitad; // Retorna la posición del vehículo

        }
        else if(idBuscado < vehiculos[mitad].id) 
        {
            fin = mitad - 1; // Buscar en la mitad izquierda
        }
        else 
        {
            inicio = mitad + 1; // Buscar en la mitad derecha
        }
    }
    return -1; // Vehículo no encontrado    
}

// 3. Función para generar el vector de rendimientos

void generarVectorRendimientos(Vehiculo vehiculos[], int nVehiculos, Viaje viajes[], int nViajes, Rendimiento rendimientos[], int &nRend)
{
    int i = 0, j=0;
    nRend = 0;

    while(i < nVehiculos)
    {
        int idActual = vehiculos[i].id;
        float sumaKm = 0, sumaLitros = 0;
        while(j< nViajes && viajes[j].id < idActual)
        {
            j++;
        }
        while(j<nViajes && viajes[j].id == idActual)
        {
            float distancia = viajes[j].distancia;
            float litros = viajes[j].litros;
            sumaKm += distancia;
            sumaLitros += litros;
            j++;
        }
        rendimientos[nRend].id = vehiculos[i].id;
        rendimientos[nRend].tipoVehiculo = vehiculos[i].tipoVehiculo;
        rendimientos[nRend].patente = vehiculos[i].patente;
        rendimientos[nRend].totalKm = sumaKm;
        rendimientos[nRend].rendReal = (sumaKm > 0 && sumaLitros > 0) ? (sumaKm / sumaLitros) : 0;
        rendimientos[nRend].rendEsperado = 1 / vehiculos[i].consumo;
        rendimientos[nRend].zona = vehiculos[i].zona;
        nRend++;
        i++;
    }

}

// 4. Función para ordenar por zona

void ordenarPorZona(Rendimiento rendimientos[], int nRend)
{
    bool ordenado = false;
    int i = 0;

    while(i < nRend - 1 && !ordenado)
    {
        ordenado = true;
        for(int j = 0; j < nRend - i - 1; j++)
        {
            if(rendimientos[j].zona > rendimientos[j + 1].zona)
            {
                Rendimiento aux = rendimientos[j];
                rendimientos[j] = rendimientos[j + 1];
                rendimientos[j + 1] = aux;
                ordenado = false; // Se realizó un intercambio, no está ordenado
            }   
        }
        i++;
    }
}

// 5. Función para generar el reporte por zona

void reportePorZona(Rendimiento rendimientos[], int nRend)
{
    int i = 0;
    string nombresZonas[] = {"Centro", "Norte", "Sur"};

    cout << "Reporte por Zona - Rendimiento de Vehiculos" << endl;
    cout << "----------------------------------------" << endl;

    while (i < nRend)
    {
        int zonaActual = rendimientos[i].zona;
        float totalKmZona = 0;
        float sumaRendReal = 0;
        float sumaRendEsperado = 0;
        int cantidadVehiculos = 0;

        while(i<nRend && rendimientos[i].zona == zonaActual)
        {
            totalKmZona += rendimientos[i].totalKm;
            sumaRendReal += rendimientos[i].rendReal;
            sumaRendEsperado += rendimientos[i].rendEsperado;
            cantidadVehiculos++;
            i++;
        }

        cout << endl;
        cout << "Zona "<< zonaActual<< ": " << nombresZonas[zonaActual - 1] << endl;
        cout << endl;
        cout << "Total de Kilometros Recorridos: " << totalKmZona << endl;
        if (cantidadVehiculos > 0) 
        {
            float diferenciaPromedio = 0;
            float promedioReal = 0;
            float promedioEsperado = 0;
            promedioReal = sumaRendReal / (float)cantidadVehiculos;
            promedioEsperado = sumaRendEsperado / (float)cantidadVehiculos;
            diferenciaPromedio = promedioReal - promedioEsperado;
            cout << "Promedio del Rendimiento Real: " << promedioReal << endl;
            cout << "La diferencia promedio entre el rendimiento real y el rendimiento esperado fue: "<< diferenciaPromedio << endl;
        } else {
            cout << "No hay vehículos en esta zona." << endl;
        }

    }

    cout <<endl;
    cout << "-----------------------------------------" << endl;
    cout << "Fin del reporte." << endl;    

}

void cargarDatos(Vehiculo vehiculos[], int &nVehiculos, Viaje viajes[], int &nViajes) 
{
    nVehiculos = 0;
    nViajes = 0;
    // Cargar datos de vehículos
    cout << "------------- Cargar Vehículos -------------" << endl;
    while(true)
    {
        int id;
        cout << "Ingrese ID del vehículo (0 para terminar): ";
        cin >> id;
        if (id == 0) break; // Terminar la carga de vehículos
        vehiculos[nVehiculos].id = id;
        cout << "Ingrese tipo de vehículo (1: Mini, 2: Mediano, 3: Grande): ";
        cin >> vehiculos[nVehiculos].tipoVehiculo;
        cout << "Ingrese patente: ";
        cin >> vehiculos[nVehiculos].patente;
        cout << "Ingrese consumo por kilómetro (litros/km): ";
        cin >> vehiculos[nVehiculos].consumo;
        cout << "Ingrese zona asignada (1: Centro, 2: Norte, 3: Sur): ";
        cin >> vehiculos[nVehiculos].zona;
        
        int cantidad;
        cout << "Ingrese la cantidad de viajes realizados por este vehículo: ";
        cin >> cantidad;
        for (int i = 0; i < cantidad; i++) 
        {
            cout << "Viaje " << (i + 1) << ":" << endl;
            viajes[nViajes].id = id;
            cout << "Ingrese fecha del viaje (formato DDMMAAAA): ";
            cin >> viajes[nViajes].fecha;
            cout << "Ingrese hora de inicio (formato 24hs): ";
            cin >> viajes[nViajes].hora;
            cout << "Ingrese origen: ";
            cin >> viajes[nViajes].origen;
            cout << "Ingrese destino: ";
            cin >> viajes[nViajes].destino;
            cout << "Ingrese distancia recorrida (km): ";
            cin >> viajes[nViajes].distancia;
            cout << "Ingrese litros consumidos: ";
            cin >> viajes[nViajes].litros;

            nViajes++;
        }
        nVehiculos++;


    }
    
}

int main() {
    Vehiculo vehiculos[MAX_VEHICULOS];
    Viaje viajes[MAX_VIAJES];
    Rendimiento rendimientos[MAX_RENDIMIENTOS];
    int nVehiculos = 0, nViajes = 0, nRend = 0;

    // Cargar datos de vehículos y viajes
    cargarDatos(vehiculos, nVehiculos, viajes, nViajes);

    // Buscar un vehículo por ID
    int idBuscado = 1; // Ejemplo de ID a buscar
    int posVehiculo = buscarVehiculo(vehiculos, nVehiculos, idBuscado);
    if (posVehiculo != -1) {
        cout << "Vehículo encontrado en la posición: " << posVehiculo << endl;
    } else {
        cout << "Vehículo no encontrado." << endl;
    }

    // Generar el vector de rendimientos
    generarVectorRendimientos(vehiculos, nVehiculos, viajes, nViajes, rendimientos, nRend);

    // Ordenar por zona
    ordenarPorZona(rendimientos, nRend);

    // Generar reporte por zona
    reportePorZona(rendimientos, nRend);

    return 0;
}
