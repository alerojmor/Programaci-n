/*Ingresar un valor entero N (< 30). A continuación ingresar un conjunto UNO y luego otro conjunto DOS,
ambos de N componentes.
Generar e imprimir otro conjunto TRES intercalando los valores de posición impar de DOS y
los valores de posición par de UNO.*/
#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int vec1[n];
    int vec2[n];
    int vec3[n];
    cout<<"ingrese n: ";
    cin>>n;
    cout<<endl;

    if(n<=30)
    {

        for(int i=0; i<n; i++)
        {
            cout<<"Ingrese un valor para vec1: ";
            cin>>vec1[i];
            cout<<"Ingrese un valor para vec2: ";
            cin>>vec2[i];
        }
    }
    for(int i=1; i<n; i+=2)
    {
        vec3[i]=vec2[i];


    }
    for(int i=0; i<n; i+=2)
    {
        vec3[i]=vec1[i];

    }


    for(int i=0; i<n; i++)
    {
        cout<<vec3[i];
        cout<<endl;
    }


    return 0;

}

