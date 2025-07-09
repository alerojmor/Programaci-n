#include <iostream>

using namespace std;

void ingresoNumeros(int &num1, int &num2)
{
    cout<<"Ingrese el primer numero: ";
    cin>>num1;
    cout<<endl;
    cout<<"Ingrese el segundo numero: ";
    cin>>num2;
    cout<<endl;
}

int maximo(int num1, int num2)
{

    if(num1<num2)
    {
        return num2;
    }
    else

        return num1;

}

int main()
{
    int numero1,numero2,resultado;
    ingresoNumeros(numero1,numero2);
    resultado=maximo(numero1, numero2);
    cout<<"El valor maximo es: "<<resultado<<endl;

    return 0;
}
