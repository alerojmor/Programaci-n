/*Una plataforma de servicios de transporte desea implementar un sistema para evaluar el rendimiento de sus conductores y optimizar el servicio de transporte de la ciudad.
La plataforma cuenta con información de cada conductor:
-nombre
-apellido
-DNI
-id de conductor(numerico)
-Zona de trabajo(1: Centro, 2: Norte, 3: Sur)

Los viajes se almacenan en un vector(ordenado por id del conductor) donde cada elemento representa un viaje realizado.
Cada conductor puede realizar multiples viajes.

De cada viaje se conoce:
-Origen
-Destino
-Fecha en formato DDMMAAAA
-Hora de Inicio (formato 24hs: 0-23)
-id del conductor(numerico)
-distancia en km
-calificacion del pasajero (entre 1 y 5)

Para evaluar el rendimiento, una plataforma de servicios de transporte calcula el indice de calidad para cada conductor:

Para cada viaje: Puntos del viaje = Calificacion x distancia
Indice de calidad = sumatoria(Puntos de cada viaje) / sumatoria(distancia total)

Se pide:
1. Definir las estructuras de datos necesarias para soportar la solución del problema.
2. Desarrollar la función buscarConductor que reciba el vector de conductores, la cantidad y un id, y devuelva la posición.
3. Implementar una funcion que genere un nuevo vector con cada conductor y su indice de calidad calculado.
El vector resultante debe incluir:
-id del conductor
-nombre
-apellido
-Distancia total
-Indice de calidad
-Zona
4. Desarrollar la funcion ordenarPorZona que ordene de forma ascendente por zona, el vector que incluye el indice de calidad de los condcutores.
5. Generar un reporte por zona que incluya:
-Nombre de la zona
-Total distancia recorrida en viajes de la zona
-Promedio de indice de calidad de la zona

Ejemplo:

Reporte por zona - Plataforma de transporte

Zona 1: Centro
Nombre de la zona: Centro
Total distancia recorrida: 2847,5 km
Promedio de indice de calidad: 3.8

Zona 2: Norte
Nombre de la zona: Norte
Total distancia recorrida: 1500 km
Promedio de indice de calidad: 4.2

Zona 3: Sur
Nombre de la zona: Sur
Total distancia recorrida: 2000 km
Promedio de indice de calidad: 3.9

Consideraciones:
a. Los datos estan previamente cargados.
b. Vector de conductores ordenado por id ascendente.
c. Vector de viajes ordenado por id de conductor ascendente.
d. Todos los conductores activos tienen al menos un viaje registrado.

Restricciones:
a. Para el punto 4 se debe usar el vector resultante del ejercicio 3.
b. Para el punto 5 se debe usar la función del punto 4.
*/

#include <iostream>
using namespace std;

// 1.Definir las estructuras de datos necesarias

struct Conductor {
    string nombre;
    string apellido;
    int dni;
    int idConductor; // numérico
    int zonaTrabajo; // 1: Centro, 2: Norte, 3: Sur 
};

struct Viaje {
    string origen;
    string destino;
    int fecha; // formato DDMMAAAA
    int horaInicio; // formato 24hs: 0-23
    int idConductor; // numérico
    float distancia; // en km
    int calificacion; // entre 1 y 5

};

struct ConductorIndice {
    int idConductor;
    string nombre;
    string apellido;
    float distanciaTotal;
    float indiceCalidad; // Índice de calidad calculado
    int zonaTrabajo; // 1: Centro, 2: Norte, 3: Sur
};

// 2. Funcion para buscar conductor por id
int buscarConductor(Conductor conductores[], int cantidad, int idBuscado)
{
    for (int i = 0; i < cantidad; i++) {
        if (conductores[i].idConductor == idBuscado) {
            return i; // Retorna la posición del conductor
        }
    }
    return -1; // Retorna -1 si no se encuentra el conductor
}

// 3. Función para generar el vector de conductores con su índice de calidad
void apareo(Conductor conductores[], int n, Viaje viajes[], int m, ConductorIndice conductoresIndice[], int &k)
{
    for (int i = 0; i < n; i++) {
        conductoresIndice[i].idConductor = conductores[i].idConductor;
        conductoresIndice[i].nombre = conductores[i].nombre;
        conductoresIndice[i].apellido = conductores[i].apellido;
        conductoresIndice[i].zonaTrabajo = conductores[i].zonaTrabajo;
        conductoresIndice[i].distanciaTotal = 0;
        conductoresIndice[i].indiceCalidad = 0;
    }
    k = n;

    for (int j = 0; j < m; j++) {
        int pos = buscarConductor(conductores, n, viajes[j].idConductor);
        if (pos != -1) {
            conductoresIndice[pos].distanciaTotal += viajes[j].distancia;
            conductoresIndice[pos].indiceCalidad += (viajes[j].calificacion * viajes[j].distancia);
        }
    }

    for (int i = 0; i < k; i++) {
        if (conductoresIndice[i].distanciaTotal > 0) {
            conductoresIndice[i].indiceCalidad /= conductoresIndice[i].distanciaTotal;
        }
    }
}

// 4. Función para ordenar por zona
void ordenarPorZona(ConductorIndice conductoresIndice[], int k) {
    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (conductoresIndice[i].zonaTrabajo > conductoresIndice[j].zonaTrabajo)
            {       
                // Intercambiar conductoresIndice[i] y conductoresIndice[j]
                ConductorIndice temp = conductoresIndice[i];
                conductoresIndice[i] = conductoresIndice[j];
                conductoresIndice[j] = temp;
            }
        }
    }
}

void mostrarConductoresIndice(ConductorIndice conductoresIndice[], int k) {
    cout << "Conductores con Índice de Calidad:" << endl;
    for (int i = 0; i < k; i++) {
        cout << "ID: " << conductoresIndice[i].idConductor
             << ", Nombre: " << conductoresIndice[i].nombre
             << ", Apellido: " << conductoresIndice[i].apellido
             << ", Distancia Total: " << conductoresIndice[i].distanciaTotal
             << ", Índice de Calidad: " << conductoresIndice[i].indiceCalidad
             << ", Zona: " << conductoresIndice[i].zonaTrabajo << endl;
    }
}

// 5. Generar reporte por zona
void generarReportePorZona(ConductorIndice conductoresIndice[], int k) {
    float totalDistancia[3] = {0, 0, 0}; // Total distancia por zona
    float indiceCalidad[3] = {0, 0, 0}; // Suma de índices de calidad por zona
    int count[3] = {0, 0, 0}; // Contador de conductores por zona
    for (int i = 0; i < k; i++) {
        int zona = conductoresIndice[i].zonaTrabajo - 1; // Ajustar índice de zona
        totalDistancia[zona] += conductoresIndice[i].distanciaTotal;
        indiceCalidad[zona] += conductoresIndice[i].indiceCalidad;
        count[zona]++;
    }
    // Mostrar reporte
    cout << "Reporte por Zona:" << endl;
    for (int i = 0; i < 3; i++) {
        if(i == 0) {
            cout << "Zona 1: Centro" << endl;
        } else if (i == 1) {
            cout << "Zona 2: Norte" << endl;
        } else {
            cout << "Zona 3: Sur" << endl;
        }
        cout << "  Total Distancia: " << totalDistancia[i] << " km" << endl;
        cout << "  Indice de Calidad: ";
        if (count[i] > 0) {
            cout << (indiceCalidad[i] / count[i]) << endl;
        } else {
            cout << "No hay conductores en esta zona." << endl;
        }
    }
}

int main() {
    // Ejemplo de uso
    Conductor conductores[] = {
        {"Juan", "Perez", 12345678, 1, 1},
        {"Maria", "Gomez", 23456789, 2, 2},
        {"Carlos", "Lopez", 34567890, 3, 3},
        {"Ana", "Martinez", 45678901, 4, 1},
        {"Luis", "Fernandez", 56789012, 5, 2}
    };
    int n = sizeof(conductores) / sizeof(conductores[0]);

    Viaje viajes[] = {
        {"A", "B", 01012023, 10, 1, 5.0, 4},
        {"C", "D", 02012023, 11, 2, 10.0, 5},
        {"E", "F", 03012023, 12, 3, 15.0, 3},
        {"G", "H", 04012023, 13, 1, 20.0, 2},
        {"I", "J", 05012023, 14, 2, 25.0, 4},
        {"K", "L", 06012023, 15, 3, 30.0, 5}
    };
    int m = sizeof(viajes) / sizeof(viajes[0]);

    ConductorIndice conductoresIndice[10]; // Suponiendo un máximo de 10 conductores
    int k;
    
    apareo(conductores, n, viajes, m, conductoresIndice, k);
    
    // Calcular índice de calidad
    for (int i = 0; i < k; i++) {
        conductoresIndice[i].distanciaTotal = viajes[i].distancia;
        conductoresIndice[i].indiceCalidad = (viajes[i].calificacion * viajes[i].distancia) / viajes[i].distancia;
    }

    ordenarPorZona(conductoresIndice, k);
    mostrarConductoresIndice(conductoresIndice, k);
    cout << endl;
    
    generarReportePorZona(conductoresIndice, k);

    return 0;
}

// Fin del código

