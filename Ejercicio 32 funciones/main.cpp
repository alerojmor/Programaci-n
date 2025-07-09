#include <iostream>
using namespace std;

/*
 *
 *
 * Una compañía aérea desea emitir un listado con los movimientos mensuales de sus M vuelos al exterior.
Para ello cuenta con la siguiente información. De cada vuelo realizado el número de vuelo, destino, y cantidad de
asientos. De cada pasajero el número de pasaporte y el importe que abonó por el pasaje en dólares.
La información finaliza con un número de pasaporte igual a cero. Se pide emitir el siguiente listado:
 *
 *
 */
void calculo();

void leer(string mensaje, int& valor) {
    cout << mensaje << endl;
    cin >> valor;
    return;
}

void leer(string mensaje, float& valor) {
    cout << mensaje << endl;
    cin >> valor;
    return;
}

void leer(string mensaje, string valor) {
    cout << mensaje << endl;
    cin >> valor;
    return;
}

void leerDatosVuelo(int& nroVuelo, string& destino, int& cantAsientos) {
    leer("Ingrese el numero de vuelo:", nroVuelo);
    leer("Ingrese el destino:", destino);
    leer("Ingrese cantidad de asientos: ", cantAsientos);
}

float getMayor(float val1, float val2) {
    if (val1 > val2) {
        return val1;
    }
    return val2;
}

void actualizarMayor(int& nroVueloMayor, float& max, int nroVuelo, float val) {
    if(val > max) {
        max = val;
        nroVueloMayor = nroVuelo;
    }

    return;
}

int porcentaje(int cantPasajeros,int cantAsientos) {
    return ((float)cantPasajeros / cantAsientos) * 100;
}

int main () {

    int cantVuelos;
    int nroVuelo, cantAsientos;
    string destino, textoPasajeros;

    int pasaporte, cantPasajeros = 0, consecutivos = 0,  nroMayorVuelo = 0;
    float importe, importeVuelo = 0, importeTotal = 0, mayor = 0;

    bool anteriorCompleto = false;

    cout << "Ingrese la cantidad de vuelos:";
    cin >> cantVuelos;

    for(int i = 0; i < cantVuelos; i++) {
        leerDatosVuelo(nroVuelo, destino, cantAsientos);

        importeVuelo = 0;
        cantPasajeros = 0;
        leer("Ingrese el pasaporte: ",pasaporte);
        while(pasaporte != 0) {
            leer("Ingrese el importe en u$d: ", importe);
            importeVuelo += importe;
            cantPasajeros++;

            // Imprimimos el renglon del pasajero
            cout << "\t\t" << pasaporte << "\t" << importe << endl;

            leer("Ingrese el pasaporte", pasaporte);
        }

        if (cantPasajeros == cantAsientos && anteriorCompleto) {
            consecutivos++;
        }
        anteriorCompleto = cantPasajeros == cantAsientos;

        importeTotal += importeVuelo;

        actualizarMayor(nroMayorVuelo, mayor, nroVuelo, importeVuelo);

        int porcentajeOcupado = porcentaje(cantPasajeros, cantAsientos);

        cout << "Nro de Vuelo: " << nroVuelo << "\t" << "Destino: " << destino << endl <<endl;
        cout << "\tNro de pasaporte: \t" << "Importe en (usd)" << endl;

        cout << textoPasajeros << endl;
        cout << endl << endl;

        cout << "Importe total del vuelo: " << importeVuelo << endl;
        cout << "Porcentaje de asientos ocupados: " << porcentajeOcupado << "% " << endl;
        cout << "Porcentaje de asientos libres: " << (100 - porcentajeOcupado) << "% " << endl;
        cout << endl;
    }

    cout << "El total recaudado es: " << importeTotal << endl;
    cout << "Cantidad de veces seguidas que se vendieron vuelos completos : " << consecutivos << endl;
    cout << "El numero de vuelo que mas recaudo: " << nroMayorVuelo  << endl;

    return 0;
}
