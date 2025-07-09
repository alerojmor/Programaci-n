#include <iostream>

using namespace std;


int main () {
int resultado = 1;
int valorUsuario = 1;
int cantidadIngresos = 0;

//pedir por pantalla
cout << "Ingrese valor a multiplicar: ";
cin >> valorUsuario;

while(valorUsuario != 0)
{
//multiplico y guardo en resultado
resultado = resultado * valorUsuario;
cantidadIngresos++;

//vuelvo a pedi por pantalla
cout << "Ingrese valor a multiplicar: ";
cin >> valorUsuario;

}

// final: muestro por pantalla.
cout << resultado;

return 0;
}
