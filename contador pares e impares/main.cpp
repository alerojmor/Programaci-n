#include <iostream>

using namespace std;

int main () {

int contadorImpares = 0;
int contadorPares = 0;
int acumuladorPares = 0;
int acumuladorImpares = 0;
int numeroUsuario = 0;

cout << "Ingrese un numero: ";
cin >> numeroUsuario;


while (numeroUsuario != 0)
{
// Hago mis calculos

// verifico si es par
if (numeroUsuario % 2 == 0){
contadorPares++;
acumuladorPares = acumuladorPares + numeroUsuario;
}
else {
contadorImpares++;
acumuladorImpares = acumuladorImpares + numeroUsuario;
}

// Vuelvo a pedir datos al usuario.
cout << "Ingrese un numero: ";
cin >> numeroUsuario;

}

cout << "Cantidad de pares " << contadorPares << endl;
cout << "Cantidad de impares " << contadorImpares << endl;
cout << "Suma de pares " << acumuladorPares << endl;
cout << "Suma de impares " << acumuladorImpares << endl;

return 0;
}
