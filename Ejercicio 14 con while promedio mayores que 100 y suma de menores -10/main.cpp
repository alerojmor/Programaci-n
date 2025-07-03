#include<iostream>
using namespace std;

int main()
{
    int cantidad=0;
    int numero=0;
    int sumatoria=0;
    float promedio=0;
    int contador=0;

    cout<<"Ingrese un numero entero positivo: "<<endl;
    cin>>cantidad;

    while(cantidad>0)
    {
        cout<<"Ingrese un numero: "<<endl;
        cin>>numero;
        if
        (numero!=0)
        {
            if(numero>100)
            {
                promedio+=numero;
                contador++;
                cantidad--;
                cout<<"valor de cantidad si el numero es mayor que cien: "<<cantidad<<endl;

            }
            else if(numero<-10)
            {
                sumatoria+=numero;
                cantidad--;
                cout<<"valor de cantidad si el numero es menor a -10: "<<cantidad<<endl;
            }


        }
        else
        {
            sumatoria=0;
            promedio=0;

        }

    }
    if(contador==0)
    {
        cout<<"El promedio es: "<<promedio<<endl;
        cout<<"La sumatoria es: "<<sumatoria<<endl;
    }
    else
    {
        cout<<"El promedio es: "<<promedio/contador<<endl;
        cout<<"La sumatoria es: "<<sumatoria<<endl;
    }
    return 0;
}
