/* Una empresa de electrodomesticos cuenta con vendedores en diferentes sucursales. Al finalizar el mes se cuenta con los datos de cada venta ordenados por 
codigo de vendedor en forma ascendente:

- Codigo de vendedor
- Fecha de venta
- Producto vendido  
- Monto de la venta
- Comision ganada

Y en forma separada, los datos de cada vendedor:

- Codigo de vendedor
- Nombre
- Apellido
- Sucursal (1: Centro, 2: Shopping)

Los datos ya estan cargados en vectores estaticos y que cada vector tiene una variable asociada que indica la cantidad de elementos cargados.

Se asume que cada vendedor realiza al menos una venta en el mes.

---

## Se pide:

**1)** Definir las estructuras de datos necesarias para soportar la solucion del problema.

**2)** Escribir una funcion que ordene el vector de vendedores por sucursal (ordenamiento burbuja).

**3)** Escribir una funcion que busque en el vector de vendedores por codigo y devuelva la posicion en el vector (busqueda binaria).

**4)** Escribir una funcion que genere un nuevo vector con cada vendedor y su total de comisiones del mes, utilizando apareo entre ambos vectores. 
**Importante:** Si el monto de la venta supera los $20.000 y la sucursal es Centro (1), se debe aumentar la comision en un 15% antes de sumarla al total.

**5)** Escribir una funcion que muestre un reporte por sucursal indicando: nombre de la sucursal, cantidad total de ventas y el vendedor con mayor total 
de comisiones (usar corte de control).*/



#include <iostream>
#include <string>
using namespace std;

// Variables globales con datos precargados
const int MAX_VENDEDORES = 100;
const int MAX_VENTAS = 500;
const int MAX_RESULTADO = 100;

struct Vendedor
{
    int codigo;
    string nombre;
    string apellido;
    int sucursal;
    
};

struct Venta
{

    int codigoVendedor;
    int fechaVenta;
    string productoVendido;
    long precioProducto;
    double comisionGanada; 

};

void ordenarVectorVendedores(Vendedor vendedores[], int nVendedores)
{   
     for(int i = 0; i < nVendedores - 1; i++)
     {
        for(int j = 0; j < nVendedores - 1 - i; j++)
        {
            if(vendedores[j].sucursal > vendedores[j + 1].sucursal)
            {
                // Intercambiar los elementos
                Vendedor temp = vendedores[j];
                vendedores[j] = vendedores[j + 1];
                vendedores[j + 1] = temp;
            }
        }
        
     }
}



void imprimirVectorOrdenado(Vendedor vendedores[], int nVendedores)
{
    
    for(int i=0;i < nVendedores;i++)
    {
        int sucursal = vendedores[i].sucursal;
        cout << "Codigo sucursal: " << sucursal << endl;
    }



}

// Vector de vendedores (ordenado por codigo ascendente)
Vendedor vendedores[MAX_VENDEDORES] = {
    {101, "Juan", "Perez", 1},
    {103, "Ana", "Lopez", 1},
    {105, "Carlos", "Ruiz", 2},
    {107, "Maria", "Garcia", 2},
    {109, "Luis", "Martinez", 1}};
int cantVendedores = 5;

int main()
{
    //Vendedor vendedores[cantVendedores];
    ordenarVectorVendedores(vendedores, cantVendedores);
    imprimirVectorOrdenado(vendedores, cantVendedores);

    return 0;
}

/* Vector de ventas (ordenado por codigo de vendedor ascendente)
Venta ventas[MAX_VENTAS] = {
    {101, 15032024, "Heladera", 15000.0, 450.0},
    {101, 16032024, "Microondas", 25000.0, 750.0},
    {101, 18032024, "Lavarropas", 30000.0, 900.0},
    {103, 17032024, "Televisor", 18000.0, 540.0},
    {103, 20032024, "Aire Acond.", 22000.0, 660.0},
    {105, 19032024, "Cocina", 12000.0, 360.0},
    {105, 21032024, "Freezer", 16000.0, 480.0},
    {105, 22032024, "Lavavajillas", 28000.0, 840.0},
    {107, 23032024, "Heladera", 35000.0, 1050.0},
    {107, 25032024, "Televisor", 40000.0, 1200.0},
    {109, 26032024, "Microondas", 8000.0, 240.0},
    {109, 28032024, "Cocina", 45000.0, 1350.0}};
int cantVentas = 12;*/

/* Vector resultado del apareo
VendedorConTotal resultado[MAX_RESULTADO];
int cantResultado = 0;*/

