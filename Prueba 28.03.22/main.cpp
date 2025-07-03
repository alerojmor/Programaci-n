#include <iostream>
using namespace std;

int main()
{
    int indice;
    //int numero;
    //cin >> numero;
    //bool resultado;
    //resultado = true;
    cout << "Seleccione una opcion: " << endl;
    cout << "1. Para numeros de 100 a 1 " << endl;
    cout << "2. Para numeros de 1 a 100 " << endl;
    cout << "3. Factorial" << endl;
    cout << "Opción: ";
    cin >> indice;

    if(indice>=1||indice>=3){
    switch(indice)
    {
    case 1 :
        cout << "Numeros de 100 a 1 " << endl;
        for(int i = 100; i>0; i--)
        {
            cout << i << endl;
        }
        break;
    case 2 :
        cout << "Numeros de 1 a 100 " << endl;
        for(int i = 1; i < 101; i++)
        {
            cout << i << endl;
        }
        break;

        case 3 :
        cout << "Factorial de un numero " << endl;

   int n,i;
   long double factorial;
   cout << "Introduce un numero: ";
   cin >> n;
   factorial=1;
   for(i=1;i<=n;i++)
        factorial = factorial * i;
   cout << endl << "Factorial de " << n << " -> " << factorial << endl;
   break;




    }}
    else {
    cout << "Ingrese una opción valida!" << endl;}


    /*while(resultado==true)
    {

        if((resultado == true)&&(numero <= 100)&&(numero > 1))
        {

            //cout << "verdadero" << endl;
            numero -= 1;
            cout << numero << endl;
        }
        else
        {
            //cout << "falso" << endl;
            resultado = false;
        }

    }*/

    return 0;
}
