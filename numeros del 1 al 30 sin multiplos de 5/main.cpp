#include <iostream>

using namespace std;

int main()
{
    int numeroIngresado;
    cin>>numeroIngresado;

    cout<<"numeros de 1 al 30:"<<endl;
   for(int i=1;i<numeroIngresado;i++){
   if(i%3!=0){
   cout<<i;}}
   return 0;
}
