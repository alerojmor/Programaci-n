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

**4)** Escribir una funcion que genere un nuevo vector con cada vendedor 
y su total de comisiones del mes, utilizando apareo entre ambos vectores. 
**Importante:** Si el monto de la venta supera los $20.000 y la sucursal 
es Centro (1), se debe aumentar la comision en un 15% antes de sumarla al total.

**5)** Escribir una funcion que muestre un reporte por sucursal indicando: 
nombre de la sucursal, cantidad total de ventas y el vendedor con mayor total 
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
    double precioProducto;
    double comisionGanada; 

};

void ordenarVectorVendedoresPorSucursal(Vendedor vendedores[], int nVendedores)
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

void ordenarVectorVendedoresPorCodigo(Vendedor vendedores[], int nVendedores)
{
    for(int i = 0; i < nVendedores - 1; i++)
    {
        for(int j = 0; j < nVendedores - 1 - i; j++)
        {
            if(vendedores[j].codigo > vendedores[j + 1].codigo)
            {
                // Intercambiar los elementos
                Vendedor temp = vendedores[j];
                vendedores[j] = vendedores[j + 1];
                vendedores[j + 1] = temp;
            }
        }
    }
}

int buscarVendedorPorCodigo(Vendedor vendedores[], int nVendedores, int codigo)
{
    int inicio = 0;
    int fin = nVendedores - 1;

    while (inicio <= fin)
    {
        int mitad = inicio + (fin - inicio) / 2;
        if (vendedores[mitad].codigo == codigo)
            return mitad;
        else if (vendedores[mitad].codigo > codigo)
            fin = mitad - 1;
        else
            inicio = mitad + 1;
    }
    return -1; // No encontrado
}


void imprimirVectorOrdenadoSucursal(Vendedor vendedores[], int nVendedores)
{
    
    for(int i=0;i < nVendedores;i++)
    {
        int sucursal = vendedores[i].sucursal;
        cout << "Codigo sucursal: " << sucursal << endl;
    }



}
void imprimirVectorOrdenadoPorCodigo(Vendedor vendedores[], int nVendedores)
{
    
    for(int i=0;i < nVendedores;i++)
    {
        int codigo = vendedores[i].codigo;
        cout << "Codigo vendedor: " << codigo << endl;
    }

}

struct VendedorConTotal {
    int codigo;
    string nombre;
    string apellido;
    int sucursal;
    double totalComisiones;
};

void generarVectorTotalComisiones(
    Vendedor vendedores[], int cantVendedores,
    Venta ventas[], int cantVentas,
    VendedorConTotal resultado[], int &cantResultado)
{
    int i = 0, j = 0;
    cantResultado = 0;

    while (i < cantVendedores && j < cantVentas) {
        int codigoVendedor = vendedores[i].codigo;
        double total = 0;

        // Sumar todas las ventas de este vendedor
        while (j < cantVentas && ventas[j].codigoVendedor == codigoVendedor) {
            double comision = ventas[j].comisionGanada;
            // Si corresponde, aumentar la comisión en un 15%
            if (ventas[j].precioProducto > 20000 && vendedores[i].sucursal == 1) {
                comision *= 1.15;
            }
            total += comision;
            j++;
        }

        // Guardar en el vector resultado
        resultado[cantResultado].codigo = vendedores[i].codigo;
        resultado[cantResultado].nombre = vendedores[i].nombre;
        resultado[cantResultado].apellido = vendedores[i].apellido;
        resultado[cantResultado].sucursal = vendedores[i].sucursal;
        resultado[cantResultado].totalComisiones = total;
        cantResultado++;

        i++;
    }
}

void mostrarReportePorSucursal(VendedorConTotal resultado[], int cantResultado)
{
    int i = 0;
    while (i < cantResultado) {
        int sucursalActual = resultado[i].sucursal;
        string nombreSucursal = (sucursalActual == 1) ? "Centro" : "Shopping";
        int cantidadVentas = 0;
        double mayorComision = -1;
        string nombreMayor, apellidoMayor;

        // Corte de control por sucursal
        cout << "Sucursal: " << nombreSucursal << endl;

        while (i < cantResultado && resultado[i].sucursal == sucursalActual) {
            cantidadVentas++;
            if (resultado[i].totalComisiones > mayorComision) {
                mayorComision = resultado[i].totalComisiones;
                nombreMayor = resultado[i].nombre;
                apellidoMayor = resultado[i].apellido;
            }
            i++;
        }

        cout << "Cantidad total de vendedores: " << cantidadVentas << endl;
        cout << "Vendedor con mayor total de comisiones: " << nombreMayor << " " << apellidoMayor
             << " ($" << mayorComision << ")" << endl;
        cout << "----------------------------------------" << endl;
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

//Vector de ventas (ordenado por codigo de vendedor ascendente)
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
int cantVentas = 12;

// Vector resultado del apareo
VendedorConTotal resultado[MAX_RESULTADO];
int cantResultado = 0;

int main()
{


    ordenarVectorVendedoresPorSucursal(vendedores, cantVendedores);
    // Imprimir el vector ordenado por sucursal 
    imprimirVectorOrdenadoSucursal(vendedores, cantVendedores);
    // Buscar un vendedor por codigo
    ordenarVectorVendedoresPorCodigo(vendedores, cantVendedores);
    // Imprimir el vector ordenado por codigo
    imprimirVectorOrdenadoPorCodigo(vendedores, cantVendedores);
    // Buscar un vendedor por codigo
    buscarVendedorPorCodigo(vendedores, cantVendedores, 105);
    // Generar el vector resultado con las comisiones totales por vendedor
    generarVectorTotalComisiones(vendedores, cantVendedores, ventas, cantVentas, resultado, cantResultado);
    // Después de generar el vector resultado y su cantidad:
    mostrarReportePorSucursal(resultado, cantResultado);
    // Imprimir el vector resultado

    
    
    return 0;
}



